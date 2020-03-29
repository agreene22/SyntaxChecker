#include <iostream>
#include <fstream>
#include "GenStack.h"

using namespace std;

class SyntaxChecker{
public:
  SyntaxChecker();
  SyntaxChecker(string fileName);
  SyntaxChecker(GenStack<char>* stack, string fileName);
  ~SyntaxChecker();

  void DelimeterCheck();

private:
  GenStack<char>* m_stack;
  string m_fileName;
};
