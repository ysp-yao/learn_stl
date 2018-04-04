#include <algorithm>
#include <vector>
#include <functional>
#include <iostream>
//#include <bind>
using namespace std;

template<class T>
struct display {
  void operator()(const T& x) const {
    cout << x << ' ';
  }
};

struct even {
  bool operator()(int x) const {
    return x%2 ? false : true;
  }
};

class even_by_two {
public:
  int operator()() const {
    return _x += 2;
  }
private:
  static int _x;
};

int even_by_two::_x = 0;

int main() {

  int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  vector<int> iv(ia, ia+sizeof(ia)/sizeof(int));

  cout << *adjacent_find(iv.begin(), iv.end()) << endl;
  cout << *adjacent_find(iv.begin(), iv.end(), equal_to<int>()) << endl;

  cout << count(iv.begin(), iv.end(), 6) << endl;
  cout << count_if(iv.begin(), iv.end(), bind(less<int>(), placeholders::_1, 7)) << endl;


  return 0;
}



