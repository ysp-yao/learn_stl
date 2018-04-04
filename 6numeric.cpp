#include <numeric>
#include <vector>
#include <functional>
#include <iostream>
#include <iterator>
using namespace std;

int main() {
  
  vector<int> iv{1, 2, 3, 4, 5};

  cout << accumulate(iv.begin(), iv.end(), 0) << endl;
  // 15, 0 + 1 + 2 + 3 + 4 + 5
 
  cout << accumulate(iv.begin(), iv.end(), 0, minus<int>()) << endl;
  // -15, 0 - 1 - 2 - 3 - 4 - 5
  // init = binary_op(init, *iter)

  cout << inner_product(iv.begin(), iv.end(), iv.begin(), 10) << endl;
  // 65, 10 + 1*1 + 2*2 + 3*3 + 4*4 + 5*5

  cout << inner_product(iv.begin(), iv.end(), iv.begin(), 10, minus<int>(), plus<int>()) << endl;
  // -20, 10 - 1+1 - 2+2 - 3+3 - 4+4 - 5+5
  // binary_op1(init, binary_op2(*iter1, *iter2))

  ostream_iterator<int> oite(cout, " ");

  auto result = partial_sum(iv.begin(), iv.end(), oite);
  cout << endl;
  // cout << *result << endl;
  // 1 3 6 10 15
  
  partial_sum(iv.begin(), iv.end(), oite, minus<int>());
  cout << endl;
  // 1 -1 -4 -8 -13
  // value = binary_op(value, *iter)

  adjacent_difference(iv.begin(), iv.end(), oite);
  cout << endl;
  // 1 1 1 1 1

  adjacent_difference(iv.begin(), iv.end(), oite, plus<int>());
  cout << endl;
  // 1 3 5 7 9a
  // v[n] = binary_op(v[n], v[n-1])

  // SGI STL
  // cout << power(10, 3) << endl; // 10*10*10
  // cout << power(10, 3, plus<int>()) << endl; // 10+10+10

  // SGI STL
  // int n = 3;
  // iota(iv.begin(), iv.end(), n);
  // for (int i=0; i<iv.size(); ++i)
  //   cout << iv[i] << " ";
  // cout << endl;

  return 0;
}
