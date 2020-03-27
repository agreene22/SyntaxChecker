#include "FileIO.h"

FileIO::FileIO(){
  m_fileName = "";
  lineCount = 0;
}

FileIO::FileIO(string fileName){
  m_fileName = fileName;
  lineCount = 0;
}

void FileIO::openFile(){
  string currLine = "";

  inFS.open(m_fileName);

  if(!inFS.is_open()){
    cout << "Error: could not open file" << endl;
    exit(0);
  }
}

void FileIO::processFile(){
  GenStack *stack = new GenStack();

  // while(!inFS.eof()){
  //   inFS >> currLine;
  //   lineCount++;
  //   for(int i = 0; i < currLine.size(); ++i){
  //     if(currLine[i] == '(' || currLine[i] == '{' || currLine[i] == '['){ // This seems like it should be in my other file
  //       stack.push(currLine[i]);
  //     }
  //     if(currLine[i] == '('){
  //       stack.push(currLine[i]);
  //     }
  //     if(currLine[i] == ')'){
  //       stack.pop();
  //     }
  //     if(currLine[i] == '{'){
  //       stack.push(currLine[i]);
  //     }
  //     if(currLine[i] == '}'){
  //       stack.pop();
  //     }
  //
  //   }
  // }

  delete stack;
}
