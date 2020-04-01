#include "EmptyStackException.h"

EmptyStackException::EmptyStackException(){
  errMessage = "";
}

EmptyStackException::EmptyStackException(string err){
  errMessage = err;
}

string EmptyStackException::getMessage(){
  return errMessage;
}
