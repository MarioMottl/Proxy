import socket

HOST = 'localhost'  # The server's hostname or IP address
PORT = 3003        # The port used by the server

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    cmd = input('$ ')
    s.sendall(bytes(cmd,"UTF-8"))
    data = s.recv(1024)

print('Received', repr(data))