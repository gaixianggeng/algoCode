#include "chapter.h"
#include <iostream>

using namespace std;

int main() {
  int pos;
  cout << "Please enter a position: ";
  cin >> pos;
  int elem;
  if (fibon_elem(pos, elem)) {
    cout << "element # " << pos << " is " << elem << endl;
  } else {
    cout << "Sorry. Could not calculate element # " << pos << endl;
  }
  return 0;
}

bool fibon_elem(int pos, int &elem) {
  if (pos <= 0 || pos > 1024) {
    elem = 0;
    return false;
  }
  int n_1 = 1, n_2 = 1;
  for (int i = 3; i <= pos; i++) {
    elem = n_1 + n_2;
    n_2 = n_1;
    n_1 = elem;
  }
  return true;
}
