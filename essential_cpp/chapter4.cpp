#include <string>
#include <vector>
using namespace std;
class Stack {
public:
  bool push(const string &);
  bool pop(string &elem);
  bool peek(string &elem);
  bool empty();
  bool full();
  int size() { return _stack.size(); }

private:
  vector<string> _stack;
}
