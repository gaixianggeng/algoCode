#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
  cout << "Hello, World!" << endl;
  return 0;
}

int fibon_elem(int pos) {
  if (pos <= 0 || pos > 1024) {
    exit(1);
  }
  int elem;
  int n_1 = 1, n_2 = 1;
  for (int i = 3; i <= pos; i++) {
    elem = n_1 + n_2;
    n_2 = n_1;
    n_1 = elem;
  }
  return elem;
}
