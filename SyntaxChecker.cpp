#include "SyntaxChecker.h"

SyntaxChecker::SyntaxChecker(){
  m_stack = new GenStack<char>();
}

SyntaxChecker::SyntaxChecker(string fileName){
  m_stack = new GenStack<char>();
  m_fileName = fileName;
}

SyntaxChecker::SyntaxChecker(GenStack<char>* stack, string fileName){
  m_stack = stack;
  m_fileName = fileName;
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
    getline(inFS, currLine);
    lineCount++;
    // cout << lineCount << " " << currLine << endl;
    for(int i = 0; i < currLine.size(); i++){
      if(currLine[i] == '(' || currLine[i] == '{' || currLine[i] == '['){
        m_stack->push(currLine[i]);
      }
      // char top = m_stack->peek();
      if(currLine[i] == ')' || currLine[i] == '}' || currLine[i] == ']'){
        if(m_stack->isEmpty()){
          cout << "Error: unexpected delimeter on line " << lineCount << endl;
          inFS.close();
          exit(1);
        }
      }
      if(currLine[i] == ')'){
        if(m_stack->peek() != '('){
          if(m_stack->peek() == '{')
            cout << "Error: expected '(' found '{' on line " << lineCount << endl;
          if(m_stack->peek() == '[')
            cout << "Error: expected '(' found '[' on line " << lineCount << endl;
          inFS.close();
          exit(1);
        }
        m_stack->pop();
      }
      if(currLine[i] == '}'){
        if(m_stack->peek() != '{'){
          if(m_stack->peek() == '(')
            cout << "Error: expected '{' found '(' on line " << lineCount << endl;
          if(m_stack->peek() == '[')
            cout << "Error: expected '{' found '[' on line " << lineCount << endl;
          inFS.close();
          exit(1);
        }
        m_stack->pop();
      }
      if(currLine[i] == ']'){
        if(m_stack->peek() != '['){
          if(m_stack->peek() == '{')
            cout << "Error: expected '[' found '{' on line " << lineCount << endl;
          if(m_stack->peek() == '(')
            cout << "Error: expected '[' found '(' on line " << lineCount << endl;

          exit(1);
        }
        m_stack->pop();
      }
    }
  }
  if(!m_stack->isEmpty()){
    switch(m_stack->peek()){
      case '(':
        cout << "Error: Reached end of file missing ')'" << endl;
        break;
      case '{':
        cout << "Error: Reached end of file missing '}'" << endl;
        break;
      case '[':
        cout << "Error: Reached end of file missing ']'" << endl;
        break;
    }
    inFS.close();
    exit(1);
  }
  cout << "Syntax Correct!" << endl;
  inFS.close();
}
