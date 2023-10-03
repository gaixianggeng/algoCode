#include "chapter.h"

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  vector<int> const vec(arr, arr + 5);
  int value = 3;

  const int *p = find(vec, value);
  cout << *p << endl;
  cout << *findTemp(arr, arr + 5, value) << endl;
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
const elemType *findTemp(const elemType *first, const elemType *last,
                         const elemType &value) {
  if (!first || !last) {
    return 0;
  }
  for (; first != last; ++first) {
    if (*first == value) {
      return first;
    }
  }
  return 0;
}
