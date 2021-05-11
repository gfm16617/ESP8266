import socket

serverPort = 3001

serverSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

serverSocket.bind(('', serverPort))
print("The server is ready to receive")

while 1:
   message, clientAddress = serverSocket.recvfrom(2048)
   print(message)

   
