import socket

serverPort = 3000

print("Starting TCP server...")
serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serverSocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

serverSocket.bind(('', serverPort))

# Listen for incoming connections
serverSocket.listen(1)

while True:
  print("")
  print("Waiting for connection...")
  connectionSocket, addr = serverSocket.accept()
  print("Connection established IP: " + addr[0] + " Port: " + str(addr[1]))

  message = connectionSocket.recv(1024)
  print("MSG: " + str(message.decode('utf-8')))
  
  connectionSocket.close()
  print("Connection closed.")
  print("")
