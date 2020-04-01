#include <iostream>
using namespace std;

class EmptyStackException{
public:
  EmptyStackException();
  EmptyStackException(string err);

  string getMessage();
private:
  string errMessage;
};
