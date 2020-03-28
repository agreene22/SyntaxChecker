#include "SyntaxChecker.h"

SyntaxChecker::SyntaxChecker(){
  m_stack = new GenStack();
  // m_size = 128;
  // m_delimeters = "";
}

SyntaxChecker::SyntaxChecker(GenStack<char>* stack, string fileName){
  m_stack = stack;
  m_fileName = fileName;
  // m_size = size;
  // m_delimeters = delimeters;
  // m_lineTracker = lineTracker;
}

bool SyntaxChecker::DelimeterCheck(){
  ifstream inFS;
  ofstream outFS;
  string currLine = "";
  int lineCount = 0;

  inFS.open(m_fileName);

  if(!inFS.is_open()){
    cout << "Error could not open file" << endl;
    exit(1);
  }

  while(!inFS.eof()){
    inFS >> currLine;
    lineCount++;
    for(int i = 0; i < currLine.size(); i++){
      if(currLine[i] == '(' || currLine[i] == '{' || currLine[i] == '['){
        stack.push(currLine[i]);
      }
      if(currLine[i] == ')' || currLine[i] == '}' || currLine[i] == ']'){
        if(stack->isEmpty()){
          cout << "Error: line " >> lineCount << endl;
          break;
        }
      }
      if(currLine[i] == ')'){
        if(stack->peek() != '('){
          cout << "Error: line " << lineCount << endl;
          break; // should it be an exit instead
        }
        stack->pop();
      }
    }
  }
}
