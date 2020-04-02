/*
Anna Greene - 2314663
Assignment 3
This file creates a Stack which can hold any data type and does the method definitions
 */

#include <iostream>
#include "EmptyStackException.h"
using namespace std;

// Template class for General Stack which can hold any data type
template <class T>
class GenStack{
public:
  GenStack(); // default constructor
  GenStack(int maxSize); // overloaded constructor
  ~GenStack(); // destructor

  //core functions
  void push(T data); // insert an item
  T pop() throw (EmptyStackException); //remove

  //aux/helper functions
  T peek();
  bool isEmpty();
  bool isFull();

private:
  int top;
  int mSize;

  T *myArray; // declaring array pointer
};

//default constructor
template <class T>
GenStack<T>::GenStack(){
  myArray = new T[1000]; // initiliazing array to default size 1000
  mSize = 1000; // initializing size to 1000
  top = -1; // initializing top to index -1
}
//overloaded constructor
// initializes values to parameter and top index to -1
template <class T>
GenStack<T>::GenStack(int maxSize){
  myArray = new T[maxSize]; //on the heap
  mSize = maxSize;
  top = -1;
}

template <class T>
GenStack<T>::~GenStack(){
  delete myArray; // deletes array pointer
}

template <class T>
void GenStack<T>::push(T data){
  //checks if full before attempting to push/insert
  if(isFull()){
    mSize++; // incrementing size
    T *newArray = new T[mSize]; // declaring and initliazing a new array with new size
    for(int i = 0; i < (mSize-1); ++i){ // filling new array with values from original
      newArray[i] = myArray[i];
    }
    myArray = newArray; // changing pointer to the new array
  }
  myArray[++top] = data; //pre-increment so it goes from -1 to 0
}

template <class T>
T GenStack<T>::pop() throw (EmptyStackException){
  //checks if empty before attempting to remove
  // if empty throws EmptyStackException
  if(top == -1){
    throw EmptyStackException("EmptyStackException: Stack is empty, nothing to pop");
  }
  return myArray[top--]; //decrement after returning the value
}

// returns top value of stack
template <class T>
T GenStack<T>::peek(){
  return myArray[top];
}

// checks if stack is full and returns a boolean
template <class T>
bool GenStack<T>::isFull(){
  return (top == mSize-1);
}

// checks if stack is empty and returns a boolean
template <class T>
bool GenStack<T>::isEmpty(){
  return (top == -1);
}
