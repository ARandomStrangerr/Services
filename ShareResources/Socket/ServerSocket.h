#include "ClientSocket.cpp"
#include "iostream"
#include "sys/socket.h"
#include "netinet/in.h"

class ServerSocket{
private:
  int port;
  int serverSocket;
public:
  ServerSocket(int, int);
  int getPort();
  ClientSocket acceptSocket();
  friend std::ostream& operator<< (std::ostream&, const ServerSocket&);
};
