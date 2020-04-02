/*
Anna Greene - 2314663
Assignment 3
This file defines all the methods for the syntax checker and implements the stacks
 */

#include "SyntaxChecker.h"

// Default constructor
SyntaxChecker::SyntaxChecker(){
  m_stack = new GenStack<char>(); // initializes GenStack
}

//Constructor if file name is given
SyntaxChecker::SyntaxChecker(string fileName){
  m_stack = new GenStack<char>(); // initializes GenStack
  m_fileName = fileName; // sets member variable to equal fileName provided
}

// Overloaded constructor
SyntaxChecker::SyntaxChecker(GenStack<char>* stack, string fileName){
  m_stack = stack; // initializes member variables to parameters
  m_fileName = fileName;
}

// Destructor
SyntaxChecker::~SyntaxChecker(){
  delete m_stack; // delete stack pointer
}

// Opens a file string and reads in source code
// Checks if delimeters are correct in the file
void SyntaxChecker::DelimeterCheck(){
  ifstream inFS; // Creating instance of fileStream
  // ofstream outFS;
  string currLine = "";
  int lineCount = 0;

  inFS.open(m_fileName); // opening file

  if(!inFS.is_open()){ // If the file does not open the program exits
    cout << "Error could not open file" << endl;
    exit(1);
  }

  // Runs until the end of the file is reached
  while(!inFS.eof()){
    getline(inFS, currLine); // Reads in each line of the file
    lineCount++; // increments line count

    // For loop to check the characters of each line
    for(int i = 0; i < currLine.size(); i++){
      if(currLine[i] == '(' || currLine[i] == '{' || currLine[i] == '['){
        m_stack->push(currLine[i]); // If the character is an opening delimeter it is pushed onto the stack
      }
      // if it is a closing delimeter it checks if the stack is empty
      if(currLine[i] == ')' || currLine[i] == '}' || currLine[i] == ']'){
        if(m_stack->isEmpty()){ // if stack is empty returns and error and exits the program
          cout << "Error: unexpected delimeter on line " << lineCount << endl;
          inFS.close(); // closes the file stream
          exit(1);
        }
      }
      if(currLine[i] == ')'){
        if(m_stack->peek() != '('){ // If the delimeter on top of the stack does not match return an error message and exit the program
          if(m_stack->peek() == '{')
            cout << "Error: expected '(' found '{' on line " << lineCount << endl;
          if(m_stack->peek() == '[')
            cout << "Error: expected '(' found '[' on line " << lineCount << endl;
          inFS.close(); // closes the file stream
          exit(1);
        }
        try{
          m_stack->pop(); // tries to pop the top of the stack
        }catch (EmptyStackException e){ // Catch EmptyStackException if stack is empty
          cout << e.getMessage() << endl;
        }

      }
      if(currLine[i] == '}'){
        if(m_stack->peek() != '{'){ // If the delimeter on top of the stack does not match return an error message and exit the program
          if(m_stack->peek() == '(')
            cout << "Error: expected '{' found '(' on line " << lineCount << endl;
          if(m_stack->peek() == '[')
            cout << "Error: expected '{' found '[' on line " << lineCount << endl;
          inFS.close(); // file stream is closed
          exit(1);
        }
        try{
          m_stack->pop(); // tries to pop the top of the stack
        }catch (EmptyStackException e){ // Catch EmptyStackException if stack is empty
          cout << e.getMessage() << endl;
        }
      }
      if(currLine[i] == ']'){
        if(m_stack->peek() != '['){ // If the delimeter on top of the stack does not match return an error message and exit the program
          if(m_stack->peek() == '{')
            cout << "Error: expected '[' found '{' on line " << lineCount << endl;
          if(m_stack->peek() == '(')
            cout << "Error: expected '[' found '(' on line " << lineCount << endl;
          inFS.close(); // closes file stream
          exit(1);
        }
        try{
          m_stack->pop(); // tries to pop the top of the stack
        }catch (EmptyStackException e){ // Catch EmptyStackException if stack is empty
          cout << e.getMessage() << endl;
        }
      }
    }
  }
  // After reading through the whole file if the stack is not empty returns error message of missing delimeter and exits the program
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
    inFS.close(); // file stream is closed
    exit(1);
  }
  cout << "Syntax Correct!" << endl; // Returns message letting user know the syntax is correct
  inFS.close(); // file stream is closed
}
