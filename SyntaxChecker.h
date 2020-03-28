#include <iostream>
#include <fstream>

using namespace std;

class SyntaxChecker{
public:
  SyntaxChecker();
  SyntaxChecker(GenStack<char>* stack, string fileName);

  bool DelimeterCheck();
  void PrintResult();
private:
  GenStack<char>* m_stack;
  string m_fileName;
  // int m_size;
  // string m_delimeters;
  // int lineTracker[];
};
