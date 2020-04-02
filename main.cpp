/*
Anna Greene - 2314663
Assignment 3
This file creates an instance of a Syntax Checker and will run as long as the user would like to
 */

#include <iostream>
#include "SyntaxChecker.h"

// main method to run instances of class
int main(int argc, char** argv){
  string fileName = ""; // declare and initliaze fileName and choice to default values
  char choice = 'y';

  if(argc > 1){ // checks to ensure a file was entered
    fileName = argv[1]; // Using command line to read in file

    // while loop to run the SyntaxChecker
    while(choice == 'y'){
      SyntaxChecker* sc = new SyntaxChecker(fileName); // Creating instance of syntax checker on the heap
      sc->DelimeterCheck(); // Running DelimeterCheck method

      // Prompting the user to choose if they would like to enter another file
      cout << "Would you like to process another file? (y/n)" << endl;
      cin >> choice; // reads in user input
      choice = tolower(choice);

      // Gets knew file name if the user is doing a second file
      if(choice == 'y'){
        cout << "Enter new file name: " << endl;
        cin >> fileName; // reads in user input
      }

      delete sc; // Deletes pointer
    }

  }else{ // if no file is given the code will not run
    cout << "INVALID USAGE: please enter name of a text file" << endl;
    cout << "USAGE: ./a.out [file name]" << endl;
  }
  return 0;
}
