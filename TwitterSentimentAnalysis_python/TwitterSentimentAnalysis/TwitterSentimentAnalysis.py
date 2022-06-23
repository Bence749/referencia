#IMPORT: Used libraries
import csv
import os.path
from os import path

import re
import nltk
import string
import pickle
from nltk.util import pad_sequence
from sklearn import model_selection
from sklearn.preprocessing import LabelEncoder

from gensim.models import keyedvectors
import gensim.downloader as gensim_api
import pandas as pd
import numpy as np

import tensorflow as tf
from tensorflow.keras import models, layers, preprocessing, utils, Sequential, initializers

def preProcess(text):
    text = re.sub(r'[@][^\s]+|http[^\s]+|[0-9][^\s]+', '', text)
    text = re.sub(r'[^\w\s]', '', str(text).lower().strip())
   

    tokenized = text.split()

    tokenized = [word for word in tokenized if word not in nltk.corpus.stopwords.words('english')]

    text = " ".join(tokenized)
    return text

data = pd.read_csv("../apple-twitter-sentiment-texts.csv")

data['tokenized_text'] = data['text'].apply(lambda x: preProcess(x))

reTrain = False

tk = preprocessing.text.Tokenizer(num_words = 10000, split = " ", lower = True, filters='!"#$%&()*+,-./:;<=>?@[\]^_`{"}~\t\n')
if reTrain == True or not(path.exists('trained_model')):
    print("Training model...")
    glove_vectors = gensim_api.load("glove-twitter-200")
    #glove_vectors = keyedvectors.load_word2vec_format("../glove.twitter.27B.50d.txt", binary = False, no_header = True)
    print('Pretrained model successfully loaded...')



    data = data.reindex(np.random.permutation(data.index))
    x_train, x_test, y_train, y_test = model_selection.train_test_split(data['tokenized_text'], data['sentiment'], test_size = 0.2, random_state = 20)
 
    tk.fit_on_texts(x_train)
    x_train_seq = tk.texts_to_sequences(x_train)
    x_test_seq = tk.texts_to_sequences(x_test)


    x_train_seq_trunc = preprocessing.sequence.pad_sequences(x_train_seq, maxlen=len(max(x_train_seq, key = len)))
    x_test_seq_trunc = preprocessing.sequence.pad_sequences(x_test_seq, maxlen=len(max(x_train_seq, key = len)))

    le = LabelEncoder()
    y_train_le = le.fit_transform(y_train)
    y_test_le = le.fit_transform(y_test)
    y_train_oh = utils.to_categorical(y_train_le)
    y_test_oh = utils.to_categorical(y_test_le)

    x_train_emb, x_valid_emb, y_train_emb, y_valid_emb = model_selection.train_test_split(x_train_seq_trunc, y_train_oh, test_size=0.3, random_state=20)

    emb_matrix = np.zeros((10000, 50))

    for i, j in tk.word_index.items():
        if j < 10000:
            if i in glove_vectors:
                emb_matrix[j] = glove_vectors[i]
        else:
            break

    model = Sequential()
    model.add(layers.Embedding(10000, 50, input_length=len(max(x_train_seq, key = len)), embeddings_initializer= initializers.Constant(emb_matrix), trainable = False))
    model.add(layers.SpatialDropout1D(0.2))
    model.add(layers.LSTM(150, dropout = 0.2, recurrent_dropout=0.2))
    model.add(layers.Dense(3, activation='softmax'))
    model.compile(loss='categorical_crossentropy', optimizer='adam', metrics=['accuracy'])

    earlyStop = tf.keras.callbacks.EarlyStopping(patience = 3, restore_best_weights = True)
    model.fit(x_train_emb, y_train_emb, validation_data=(x_valid_emb, y_valid_emb), batch_size=64, epochs=32, callbacks= earlyStop)
    scores = model.evaluate(x_test_seq_trunc, y_test_oh, verbose=0, batch_size=16)
    print(scores[1])

    model.save('trained_model')
else:
    print("Loading model...")
    model = models.load_model("trained_model")


x_test = data['tokenized_text'][:int(len(data['tokenized_text'])*0.2)]
x_test_seq = tk.texts_to_sequences(x_test)
x_test_seq_trunc = preprocessing.sequence.pad_sequences(x_test_seq, maxlen=len(max(x_test_seq, key = len)))

print(x_test_seq_trunc.shape)
y_test_predict = model.predict(x_test_seq_trunc)
y_test_predict = np.argmax(y_test_predict, axis = 1) - 1
toWrite = np.column_stack((x_test, y_test, y_test_predict))
toWrite = toWrite.tolist()
with open('test_out.csv', 'w+', encoding='utf-8', newline='') as f:
    writer = csv.writer(f)
    writer.writerow(['Text', 'Real', 'Predicted'])
    writer.writerows(toWrite)

