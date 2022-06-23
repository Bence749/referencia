import socket
import hashlib
import sys

conn = socket.socket()
server_address = (sys.argv[1], int(sys.argv[2]))
conn.connect(server_address)


file = open(sys.argv[6], "rb")
load = file.read(1024)
i = 1
while(load):
    conn.sendall(load)
    load = file.read(1024)
    
file.close()
conn.close()


file = open(sys.argv[6], "rb")
md5_hash = hashlib.md5()
content = file.read()
md5_hash.update(content)
md5_checksum = md5_hash.hexdigest()

conn = socket.socket()
server_address = (sys.argv[3], int(sys.argv[4]))
conn.connect(server_address)
inout = [conn]

conn.send((f"BE|{sys.argv[5]}|60|" + str(len(md5_checksum)) + '|' + md5_checksum).encode())

data = conn.recv(1024)

file.close()
conn.close()