#include <exception>
using namespace std;

class StackException : public exception{
  const char * what() const throw(){
    return "Empty Stack Exception: Nothing to pop";
  }
// public:
//   EmptyStackException(string err): errMsg(err){}
//   string getError({return errMsg;})
// private:
//   string errMsg;
};
