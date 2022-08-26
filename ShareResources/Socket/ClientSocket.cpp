#include "ClientSocket.h"

ClientSocket::ClientSocket(int socket){
  this -> socket = socket;
}

std::string ClientSocket::readLine(){
  char charBuffer[1024] = {0};
  std::string stringBuffer = "";
  while (true){
    read(socket, charBuffer, 1024);
    stringBuffer += std::string(charBuffer);
    if (charBuffer[1023] == 0) break;
  }
  return stringBuffer;
}

void ClientSocket::write(std::string data){
  char charBuffer[data.length() + 1] = {0};
  strcpy(charBuffer, data.c_str());
  send(socket, charBuffer, sizeof(charBuffer), 0);
  return;
}
