import select, socket
import struct
import queue
import random
import sys

randomNum = random.randrange(0, 100)

packer = struct.Struct('c I')
unpacker = struct.Struct('c I')

server = socket.socket()
server.setblocking(0)
server_address = (sys.argv[1], int(sys.argv[2]))
server.bind(server_address)
server.listen(5)

inputs = [server]
outputs_queue = {}
outputs = []
connected_s = []
live = True
finishing = False
while live:
    read_ready, write_ready, exceptions = select.select(inputs, outputs, [])
    for s in read_ready:
        if s is server:
            connection, client_address = s.accept()
            connection.setblocking(0)
            connected_s.append(connection)
            inputs.append(connection)
            outputs_queue[connection] = queue.Queue()
        else:
            message = s.recv(unpacker.size)
            if message:
                if not finishing:
                    data = unpacker.unpack(message)
                    if data[0] == b'=' and data[1] == randomNum:
                        outputs_queue[s].put(packer.pack(b'Y', 0))
                        finishing = True
                    elif data[0] == b'=' and data[1] != randomNum:
                        outputs_queue[s].put(packer.pack(b'K', 0))
                    elif data[0] == b'>' and randomNum > data[1]:
                        outputs_queue[s].put(packer.pack(b'I', 0))
                    elif data[0] == b'<' and randomNum < data[1]:
                        outputs_queue[s].put(packer.pack(b'I', 0))
                    else:
                        outputs_queue[s].put(packer.pack(b'N', 0))
                else:    
                    outputs_queue[s].put(packer.pack(b'V', 0))
                if s not in outputs:
                        outputs.append(s)
            else:
                live = False
    
    for s in write_ready:
        try:
            next_msg = outputs_queue[s].get_nowait()
        except queue.Empty:
            outputs.remove(s)
        else:
            s.send(next_msg)

    
    
server.close()