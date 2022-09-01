#include "Socket.cpp"

class ListenerTcpIp4 : public Listener {
public:
  ListenerTcpIp4(int port, int queueLength) : Listener(socket(AF_INET, SOCK_STREAM, 0), port, queueLength){}
};
