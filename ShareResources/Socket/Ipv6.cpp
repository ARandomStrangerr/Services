#include "Socket.cpp"

class ListenerTcpIp6 : public Listener {
public:
  ListenerTcpIp6(int port, int queueLength) : Listener(socket(AF_INET6, SOCK_STREAM, 0), port, queueLength){}
};
