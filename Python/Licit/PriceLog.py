import socket
import sys

server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_address = (sys.argv[1], int(sys.argv[2]))
server.bind(server_address)

data, address = server.recvfrom(4096)
price = 0

while data != b'END':
    print(data.decode('utf-8'))
    print("New price: " + str(price))
    data, address = server.recvfrom(4096)
    
server.close()