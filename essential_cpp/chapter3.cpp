#include "chapter.h"

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  vector<int> const vec(arr, arr + 5);
  int value = 3;

  const int *p = find(vec, value);
  cout << *p << endl;
  cout << *findTemp(vec, value) << endl;
  return 0;
}

const int *find(const vector<int> &vec, int value) {
  for (int ix = 0; ix < vec.size(); ++ix) {
    if (vec[ix] == value) {
      return &vec[ix];
    }
  }
  return 0;
}

template <typename elemType>
const elemType *findTemp(const vector<elemType> &vec, const elemType &value) {
  for (int ix = 0; ix < vec.size(); ++ix) {
    if (vec[ix] == value) {
      return &vec[ix];
    }
  }
  return 0;
}
