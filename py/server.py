import socket
import time

HOST = '0.0.0.0'  # Standard loopback interface address (localhost)
PORT = 3333        # Port to listen on (non-privileged ports are > 1023)

message = "A"*300

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    conn, addr = s.accept()
    with conn:
        print('Connected by', addr)
        data = conn.recv(1032)
        print(data)
        conn.sendall(bytes(message,"UTF-8"))
        """while True:
            data = conn.recv(1024)
            if not data:
                break
            conn.sendall(data)"""
    time.sleep(10)