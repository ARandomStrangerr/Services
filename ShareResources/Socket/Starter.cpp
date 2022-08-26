#include "ServerSocket.cpp"
#include "iostream"

int main(int argc, char const *argv[]) {
  ServerSocket serverSocket (9999, 20);
  std::cout << serverSocket << std::endl;

  ClientSocket socket = serverSocket.acceptSocket();
  std::cout << socket.readLine() << std::endl;

  std::string data = "DATA IS RECEIVED !";
  socket.write(data);
  return 0;
}
