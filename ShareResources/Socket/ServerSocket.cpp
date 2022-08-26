#include "ServerSocket.h"

ServerSocket::ServerSocket(int port, int queueLength){
  this -> port = port;

  /*
  int socket(domain, type, protocol)
  "sys/socket.h" must be included to run
  domain: communication domain
     AF_ LOCAL: local host
     AF_INET: IPv4
     AF_INET6: IPv6
  type: communication type
    SOCK_STREAM: TCP
    SOCK_DGRAM: UDP
  protocol: protocol value for internet protocol
    value is 0
  */
  serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSocket == 0){
      throw std::runtime_error("Cannot create the socket");
  }

  int opt = 1;
  setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

  struct sockaddr_in serverAddr;  // server info struct
  serverAddr.sin_family = AF_INET;  // TCP/IP
  serverAddr.sin_addr.s_addr = INADDR_ANY;  // server addr--permit all connection
  serverAddr.sin_port = htons(port);  //port of the
  bind(serverSocket, (struct sockaddr*) &serverAddr, sizeof(struct sockaddr));

  listen (serverSocket, 2);
}

int ServerSocket::getPort(){
  return this -> port;
}

ClientSocket ServerSocket::acceptSocket(){
  struct sockaddr_in clientAddr;
  socklen_t length = sizeof(clientAddr);
  int acceptSocket = accept(serverSocket, (struct sockaddr*) &clientAddr, &length);
  ClientSocket clientSocket(acceptSocket);
  return clientSocket;
}

std::ostream& operator<< (std::ostream& os, const ServerSocket& a){
  os << "this ServerSocket is operating on port : " << a.port << std::endl;
  return os;
}
