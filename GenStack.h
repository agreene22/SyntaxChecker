#include <iostream>
using namespace std;

template <class T>
class GenStack : public StackException{
public:
  GenStack(); // default constructor
  GenStack(int maxSize); // overloaded constructor
  ~GenStack(); // destructor

  //core functions
  void push(T data); // insert an item
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

template <class T>
GenStack<T>::~GenStack(){
  delete myArray;
  cout << "Array deleted" << endl;
}

template <class T>
void GenStack<T>::push(T data){
  //check if full before attempting to push/insert
  if(isFull()){
    mSize++;
    T *newArray = new T[mSize];
    for(int i = 0; i < (mSize-1); ++i){
      newArray[i] = myArray[i];
    }
    myArray = newArray;
  }
  myArray[++top] = data; //pre-increment so it goes from -1 to 0
}

template <class T>
T GenStack<T>::pop(){
  //check if empty before attempting to remove
  if(top == 0){
    // THROW EXCEPTION BECAUSE ITS EMPTY
  }
  return myArray[top--]; //decrement after returning the value
}

template <class T>
T GenStack<T>::peek(){
  return myArray[top];
}

template <class T>
bool GenStack<T>::isFull(){
  return (top == mSize-1);
}

template <class T>
bool GenStack<T>::isEmpty(){
  return (top == -1);
}
