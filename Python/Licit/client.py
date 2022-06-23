import socket
import struct
import sys
import json
import time

conn = socket.socket()

server_address = (sys.argv[1], int(sys.argv[2]))
conn.connect(server_address)
inout = [conn]

packer = struct.Struct('3s I')
unpacker = struct.Struct('3s I')

data = (b'TBD', 0)

with open(sys.argv[3]) as json_file:
    licits = json.load(json_file)['licits']

i = 0
while data[0] != b'END':  
    value = (b'BID', licits[i])
    print("Sent: " + str(value))
    packer_data = packer.pack(*value)
    conn.sendall(packer_data)
    packetdata = conn.recv(unpacker.size)
    data = unpacker.unpack(packetdata)
    i += 1   
    print("Received: " + str(data))
    time.sleep(1)
            
conn.close()
