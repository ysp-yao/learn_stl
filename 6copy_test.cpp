#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

using namespace std;

class C {
public:
  C():_data(3) {}
private:
  int _data;
};

int main() {
  // test 1
  const char ccs[5] = {'a', 'b', 'c', 'd', 'e'};
  char ccd[5];
  copy(ccs, ccs+5, ccd);

  // test 2
  const wchar_t cwcs[5] = {'a', 'b', 'c', 'd', 'e'};
  wchar_t cwcd[5];
  copy(cwcs, cwcs+5, cwcd);

  // test 3
  int ia[5] = {0, 1, 2, 3, 4};
  copy(ia, ia+5, ia);

  // test 4
  list<int> ilists(ia, ia+5);
  list<int> ilistd(5);
  copy(ilists.begin(), ilists.end(), ilistd.begin());

  // test 5
  vector<int> ivecs(ia, ia+5);
  vector<int> ivecd(5);
  copy(ivecs.begin(), ivecs.end(), ivecd.begin());

  // test 6
  C c[5];
  vector<C> Cvs(c, c+5);
  vector<C> Cvd(5);
  copy(Cvs.begin(), Cvs.end(), Cvd.begin());

  // test 7
  deque<C> Cds(c, c+5);
  deque<C> Cdd(5);
  copy(Cds.begin(), Cds.end(), Cdd.begin());

  // test 8
  
  // test 9


  return 0;
}
