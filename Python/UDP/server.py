import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_address = ('localhost', 10000)
sock.bind(server_address)

data, address = sock.recvfrom(4096)

print("Incoming message from " + str(address))
print("Message: " + data.decode('utf-8'))

sock.sendto(b'Hello client', address)
