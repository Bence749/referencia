import select, socket
import struct
import queue
import sys

value = 1000

packer = struct.Struct('3s I')
unpacker = struct.Struct('3s I')

server = socket.socket()
server.setblocking(0)
server_address = (sys.argv[1], int(sys.argv[2]))
server.bind(server_address)
server.listen(5)

conn = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
PriceLog_address = (sys.argv[3], int(sys.argv[4]))

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
                    print('Received: ' + str(data))
                    if data[1] >= 1000000:
                        value = data[1]
                        outputs_queue[s].put(packer.pack(b'END', value))
                        conn.sendto(b'END', PriceLog_address)
                        finishing = True
                    elif data[1] <= value:
                        outputs_queue[s].put(packer.pack(b'LOW', value))
                    elif data[1] > value:
                        value = data[1]
                        outputs_queue[s].put(packer.pack(b'OK', value))
                        conn.sendto(bytes(value), PriceLog_address)
                        
                else:    
                    outputs_queue[s].put(packer.pack(b'END', 0))
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
            print('Sent: ' + str(unpacker.unpack(next_msg)))
            

    
conn.close()
server.close()