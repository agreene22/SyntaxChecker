#include <iostream>
template<class T>;
using namespace std;

class GenStack{
public:
  GenStack(); // default constructor
  GenStack(int maxSize); // overloaded constructor
  ~GenStack(); // destructor

  //core functions
  void push(T data); // insert an item CHANGE DATA TYPE
  T pop(); //remove

  //aux/helper functions
  T peek();
  bool isEmpty();
  bool isFull();

private:
  int top;
  int mSize;

  T *myArray;
};
