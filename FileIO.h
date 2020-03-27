#include <iostream>
#include <fstream>
#include "GenStack.h"

using namespace std;

class FileIO{
public:
  FileIO();
  FileIO(string fileName);

  void openFile();
  void processFile();

private:
  string m_fileName;
  int lineCount;
  ifstream inFS;
  ofstream outFS;
};
