import socket
import select
import sys

server = socket.socket()
server.setblocking(0)
server_address = (sys.argv[1], int(sys.argv[2]))
server.bind(server_address)
server.listen(5)

inputs = [server]
outputs = list()
checksumList = []

live = True
while live:
    read_ready, write_ready, exceptions = select.select(inputs, outputs, [])

    for s in read_ready:
        # accept connection if server is read-ready
        if s is server:
            connection, client_address = s.accept()
            print("server received connection: socket " + str(connection.fileno()))
            inputs.append(connection)
        # receive message if a connection is read-ready
        else:
            message = s.recv(1024)
            if message:
                input = message.decode('utf-8').split('|')
                if(input[0] == "BE"):
                    checksumList.append(message)
                    s.send(b"OK")
                elif(input[0] == "KI"):
                    for line in checksumList:
                        data = line.decode('utf-8')
                        if(data.split('|')[1] == input[1]):
                            s.send(((data.split('|')[3]) + "|" + str(data.split('|')[4])).encode())
                    
                