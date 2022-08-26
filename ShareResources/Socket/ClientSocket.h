#include "string"
#include "cstring"
#include "unistd.h"
#include "sys/socket.h"

class ClientSocket{
private:
  int socket;
public:
  ClientSocket(int);
  std::string readLine();
  void write(std::string);
};
