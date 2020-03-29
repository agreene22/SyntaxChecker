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

SyntaxChecker::~SyntaxChecker(){
  delete m_stack;
}

void SyntaxChecker::DelimeterCheck(){
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
          exit(1);
        }
      }
      if(currLine[i] == ')'){
        if(stack->peek() != '('){
          if(stack->peek() == '{')
            cout << "Error: expected '(' found '{' on line " << lineCount << endl;
          if(stack->peek() == '[')
            cout << "Error: expected '(' found '[' on line " << lineCount << endl;
          exit(1);
        }
        stack->pop();
      }
      if(currLine[i] == '}'){
        if(stack->peek() != '{'){
          if(stack->peek() == '(')
            cout << "Error: expected '{' found '(' on line " << lineCount << endl;
          if(stack->peek() == '[')
            cout << "Error: expected '{' found '[' on line " << lineCount << endl;
          exit(1);
        }
        stack->pop();
      }
      if(currLine[i] == ']'){
        if(stack->peek() != '['){
          if(stack->peek() == '{')
            cout << "Error: expected '[' found '{' on line " << lineCount << endl;
          if(stack->peek() == '(')
            cout << "Error: expected '[' found '(' on line " << lineCount << endl;
          exit(1);
        }
        stack->pop();
      }
    }
  }
  if(!stack->isEmpty()){
    switch(stack->peek()){
      case '(':
        cout << "Error: Reached end of file missing ')'" << endl;
        break;
        exit(1);
      case '{':
        cout << "Error: Reached end of file missing '}'" << endl;
        break;
        exit(1);
      case '[':
        cout << "Error: Reached end of file missing ']'" << endl;
        break;
        exit(1);
    }
  }

  inFS.close();
}
