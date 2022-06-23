import socket

conn = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server_address = ('localhost', 10000)

conn.sendto(b'Hello server', server_address)

data, address = conn.recvfrom(4096)

print("Msg: " + data.decode('utf-8'))

conn.close()