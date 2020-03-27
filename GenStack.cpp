#include "GenStack.h"

//default constructor
template <class T>
GenStack<T>::GenStack(){
  myArray = new T[128];
  mSize = 128;
  top = -1;
}
//overloaded constructor
template <class T>
GenStack<T>::GenStack(int maxSize){
  myArray = new T[maxSize]; //on the heap
  mSize = maxSize;
  top = -1;
}

GenStack::~GenStack(){
  delete myArray;
  cout << "Array deleted" << endl;
}

template <class T>
void GenStack<T>::push(T data){
  //check if full before attempting to push/insert
  myArray[++top] = data; //pre-increment so it goes from -1 to 0
}

template <class T>
T GenStack::pop(){
  //check if empty before attempting to remove
  return myArray[top--]; //decrement after returning the value
}

template <class T>
T GenStack::peek(){
  return myArray[top];
}

bool GenStack::isFull(){
  return (top == mSize-1);
}

bool GenStack::isEmpty(){
  return (top == -1);
}