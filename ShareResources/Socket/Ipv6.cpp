#include "Socket.cpp"

class ListenerTcpIp6 : public Listener {
public:
  ListenerTcpIp6(int port, int queueLength) : Listener(AF_INET6, SOCK_STREAM, port, queueLength){}
};
