// #include "string"
#include "iostream"
#include "list"

class Link;
class Chain;

class Link {
public:
  virtual bool handle() = 0;
};

class LinkAbstract : public Link{
public:
  bool handle() override{
    std::cout << "base class called" << std::endl;
    return false;
  }
};

class Chain {
protected:
  std::list<LinkAbstract*> chain;
public:
  bool execute(){
    if (chain.empty()) throw std::length_error("the action chain is empty");
    for (std::list<LinkAbstract*>::iterator itr = chain.begin(); itr != chain.end(); itr++){
      if (!(*itr)->handle()) return false;
    }
    return true;
  }
};
