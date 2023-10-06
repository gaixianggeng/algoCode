#include "stack.h"
#include <iostream>
using namespace std;

int main() { cout << "Hello World!"; }

void fill_stack(Stack &stack, istream &is = cin) {
  string str;
  while (is >> str && !stack.full()) {
    stack.push(str);
    cout << "pushed: " << str << endl;
  }
}
