#include <iostream>
#include "SyntaxChecker.h"

int main(int argc, char** argv){
  string fileName = "";
  char choice = 'y';

  if(argc > 1){
    fileName = argv[1]; // Using command line to read in file

    while(choice == 'y'){
      SyntaxChecker* sc = new SyntaxChecker(fileName); // does this need to be on the heap
      sc->DelimeterCheck();

      cout << "Would you like to process another file? (y/n)" << endl;
      cin >> choice;
      choice = tolower(choice);

      if(choice == 'y'){
        cout << "Enter new file name: " << endl;
        cin >> fileName;
      }

      delete sc;
    }

  }else{
    cout << "INVALID USAGE: please enter name of a text file" << endl;
    cout << "USAGE: ./a.out [file name]" << endl;
  }
  return 0;
}
