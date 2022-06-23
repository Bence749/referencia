import hashlib
import socket
import sys

sock = socket.socket()

server_address = (sys.argv[1], int(sys.argv[2]))
sock.bind(server_address)
file = open(sys.argv[6], "wb")
sock.listen(5)
rcving = True

i = 1
while rcving:
    connection, client_address = sock.accept()
    load = connection.recv(1024)
    while load:
        file.write(load)
        load = connection.recv(1024)
    file.close()
    rcving = False
    sock.close()
    connection.close()

conn = socket.socket()
server_address = (sys.argv[3], int(sys.argv[4]))
conn.connect(server_address)
conn.send(f"KI|{sys.argv[5]}".encode())

md5_hash = hashlib.md5()
file = open(sys.argv[6], "rb")
content = file.read()
md5_hash.update(content)
md5_checksum = md5_hash.hexdigest()

indata = conn.recv(1024)
data = indata.decode('utf-8').split('|')
if md5_checksum == data[1]:
    print("CSUM OK")
else:
    print("CSUM CORRUPTED")
    
file.close()
conn.close()