#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

template<class T>
struct display {
  void operator()(const T& x) {
    cout << x << ' ';
  }
};

int main() {
  {
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    copy(ia+2, ia+7, ia);
    for_each(ia, ia+9, display<int>());
    cout << endl;
  }
  {
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    copy(ia+2, ia+7, ia+4);
    for_each(ia, ia+9, display<int>());
    cout << endl;
  }
  {
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    deque<int> id(ia, ia+9);

    deque<int>::iterator first = id.begin();
    auto last = id.end();
    ++++first;
    cout << *first << endl;
    ----last;
    cout << *last << endl;

    auto result = id.begin();
    cout << *result << endl;

    copy(first, last, result);
    for_each(id.begin(), id.end(), display<int>());
    cout << endl;
  }
  {
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    deque<int> id(ia, ia+9);

    deque<int>::iterator first = id.begin();
    auto last = id.end();
    ++++first;
    cout << *first << endl;
    ----last;
    cout << *last << endl;

    auto result = id.begin();
    advance(result, 4);
    cout << *result << endl;

    copy(first, last, result);
    for_each(id.begin(), id.end(), display<int>());
    cout << endl;
  }
}
