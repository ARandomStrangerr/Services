#include "Socket.cpp"

class ListenerTcpIp4 : public Listener {
public:
  ListenerTcpIp4(int port, int queueLength) : Listener(AF_INET, SOCK_STREAM, port, queueLength){}
};
