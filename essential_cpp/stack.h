#include <string>
#include <vector>
using namespace std;

class Stack {
public:
  bool push(const string &);
  bool pop(string &elem);
  bool peek(string &elem);
  bool empty() const { return _stack.empty(); }
  bool full() const { return _stack.size() == _stack.max_size(); };
  int size() { return _stack.size(); }

private:
  vector<string> _stack;
};
