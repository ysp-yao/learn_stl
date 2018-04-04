#include <algorithm>
#include <vector>
#include <vector>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

template<class T>
struct display {
  void operator()(const T& x) const {
    cout << x << ' ';
  }
};

int main() {
  int ia[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  vector<int> iv1(ia, ia+5);
  vector<int> iv2(ia, ia+9);

  auto iter_pair = mismatch(iv1.begin(), iv1.end(), iv2.begin());
  if (iter_pair.first == iv1.end()) cout << "iv1 end" << endl;
  else cout << *iter_pair.first << endl;
  if (iter_pair.second == iv2.end()) cout << "iv2 end" << endl; 
  else cout << *iter_pair.second << endl;

  cout << equal(iv1.begin(), iv1.end(), iv2.begin()) << endl;
  cout << equal(iv1.begin(), iv1.end(), &ia[3]) << endl;
  cout << equal(iv1.begin(), iv1.end(), &ia[3], less<int>()) << endl;

  fill(iv1.begin(), iv1.end(), 9);
  for_each(iv1.begin(), iv1.end(), display<int>());
  cout << endl;

  fill_n(iv1.begin(), 3, 7);
  for_each(iv1.begin(), iv1.end(), display<int>());
  cout << endl;

  auto iter1 = iv1.begin();
  auto iter2 = iter1;
  advance(iter2, 3);
  iter_swap(iter1, iter2);
  for_each(iv1.begin(), iv1.end(), display<int>());
  cout << endl;

  cout << max(*iter1, *iter2) <<endl;
  cout << min(*iter1, *iter2) <<endl;

  swap(*iv1.begin(), *iv2.begin()); // 区别iter_swap

  string stra1[] = { "Jamie", "JJHou", "Jason" };
  string stra2[] = { "Jamie", "JJhou", "Jerry" };
  cout << lexicographical_compare(stra1, stra1+2, stra2, stra2+2) << endl;
  cout << lexicographical_compare(stra1, stra1+2, stra2, stra2+2, greater<string>()) << endl;


















}





