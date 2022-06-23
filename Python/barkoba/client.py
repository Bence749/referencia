import socket
import struct
import math
import sys
import time

conn = socket.socket()

server_address = (sys.argv[1], int(sys.argv[2]))
conn.connect(server_address)
inout = [conn]
min = 0
max = 100

value = (b'>', math.ceil((max+min)/2))
packer = struct.Struct('c I')
unpacker = struct.Struct('c I')
packer_data = packer.pack(*value)

conn.sendall(packer_data)

packetdata = conn.recv(unpacker.size)
data = unpacker.unpack(packetdata)



while data[0] != b'V' and data[0] != b'K' and data[0] != b'Y':
    if max - min > 2:
        if data[0] == b'I':
            min = value[1] 
            value = (b'>', math.ceil((max+min)/2))
            packer_data = packer.pack(*value)
            conn.sendall(packer_data)
            packetdata = conn.recv(unpacker.size)
            data = unpacker.unpack(packetdata)
        else:
            max = value[1]
            value = (b'>', math.ceil((max+min)/2))
            packer_data = packer.pack(*value)
            conn.sendall(packer_data)
            packetdata = conn.recv(unpacker.size)
            data = unpacker.unpack(packetdata)
    else:
        value = (b'>', min)
        packer_data = packer.pack(*value)
        conn.sendall(packer_data)
        packetdata = conn.recv(unpacker.size)
        data = unpacker.unpack(packetdata)
        if data[0] == b'N':
            value = (b'=', min)
            packer_data = packer.pack(*value)
            conn.sendall(packer_data)
            packetdata = conn.recv(unpacker.size)
            data = unpacker.unpack(packetdata)
        else:
            value = (b'<', max)
            packer_data = packer.pack(*value)
            conn.sendall(packer_data)
            packetdata = conn.recv(unpacker.size)
            data = unpacker.unpack(packetdata)
            if data[0] == b'N':
                value = (b'=', max)
                packer_data = packer.pack(*value)
                conn.sendall(packer_data)
                packetdata = conn.recv(unpacker.size)
                data = unpacker.unpack(packetdata)
            else:
                value = (b'=', max - 1)
                packer_data = packer.pack(*value)
                conn.sendall(packer_data)
                packetdata = conn.recv(unpacker.size)
                data = unpacker.unpack(packetdata)
    print("Sent: " + str(value))
    print("Received: " + str(data))
    time.sleep(5)
            
conn.close()
