# based on https://www.youtube.com/watch?v=3QiPPX-KeSc

import socket

HEADER = 64
PORT = 4242
FORMAT = 'utf-8'
DISCONNECT_MESSAGE = "!DISCONNECT"
SERVER = "192.168.0.240"
ADDR = (SERVER, PORT)

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(ADDR)

def send(msg):
    message = msg.encode(FORMAT)
    msg_length = len(message)
    send_length = str(msg_length).encode(FORMAT)
    send_length += b' ' * ( HEADER - len(send_length) )
    client.send(send_length)
    client.send(message)

send("Hello World!")    
#send("Hello Everyone!")

#send(DISCONNECT_MESSAGE)