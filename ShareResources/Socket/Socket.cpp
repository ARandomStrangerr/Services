#include "iostream"
#include "sys/socket.h"
#include "netinet/in.h"
#include "cstring"
#include "unistd.h"

class Listener;
class Socket;

class Socket{
private:
  int socket;
public:
  Socket(int socket, std::string address, int port){
    struct sockaddr_in serverAddr;

  }
  Socket(int socket){
    this -> socket = socket;
  }

  std::string readLine(){
    char charBuffer[1024] = {0};
    std::string stringBuffer = "";
    while (true){
      read(socket, charBuffer, 1024);
      stringBuffer += std::string(charBuffer);
      if (charBuffer[1023] == 0) break;
    }
    return stringBuffer;
  }

  void write(std::string data){
    char charBuffer[data.length() + 1] = {0};
    strcpy(charBuffer, data.c_str());
    send(socket, charBuffer, sizeof(charBuffer), 0);
    return;
  }
};

class Listener{
private:
  int port;
  int serverSocket;
protected:
  Listener(sa_family_t domain, __socket_type type, int port, int queueLength){
    this -> port = port;

    /*
    int socket(domain, type, protocol)
    "sys/socket.h" must be included to run
    domain: communication domain
       AF_LOCAL: local host
       AF_INET: IPv4
       AF_INET6: IPv6
    type: communication type
      SOCK_STREAM: TCP
      SOCK_DGRAM: UDP
    protocol: protocol value for internet protocol
      value is 0
    */
    this -> serverSocket = socket(domain, type, 0);
    if (serverSocket == 0){
        throw std::runtime_error("Cannot create the socket");
    }

    int opt = 1;
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    struct sockaddr_in serverAddr;  // server info struct
    serverAddr.sin_family = domain;  // TCP/IP IPv4
    serverAddr.sin_addr.s_addr = INADDR_ANY;  // server addr--permit all connection
    serverAddr.sin_port = htons(port);  //port of the
    bind(serverSocket, (struct sockaddr*) &serverAddr, sizeof(struct sockaddr));

    listen (serverSocket, queueLength);
  }
public:
  int getPort(){
    return this -> port;
  }

  Socket acceptSocket(){
    struct sockaddr_in clientAddr;
    socklen_t length = sizeof(clientAddr);
    int acceptSocket = accept(serverSocket, (struct sockaddr*) &clientAddr, &length);
    Socket clientSocket(acceptSocket);
    return clientSocket;
  }

  friend std::ostream& operator<< (std::ostream& os, const Listener& a){
    os << "this ServerSocket is operating on port : " << a.port << std::endl;
    return os;
  }
};
