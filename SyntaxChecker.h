/*
Anna Greene - 2314663
Assignment 3
This file is the header for the SyntaxChecker declaring the methods and member variables
 */

#include <iostream>
#include <fstream>
#include "GenStack.h"

using namespace std;

// Class to check the syntax of a file
class SyntaxChecker{
public:
  //constructors
  SyntaxChecker();
  SyntaxChecker(string fileName);
  SyntaxChecker(GenStack<char>* stack, string fileName);
  //destructor
  ~SyntaxChecker();

  void DelimeterCheck(); // method to check delimeters

private:
  GenStack<char>* m_stack; // Stack member variable declared
  string m_fileName; // String to represent file name declared
};
