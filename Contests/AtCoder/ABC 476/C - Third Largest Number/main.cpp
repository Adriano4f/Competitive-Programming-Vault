#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  size_t N; cin >> N;
  vector<int32_t> A(N);
  for ( auto & a : A )
    cin >> a;

  multiset<int32_t, greater<int32_t>> mset;
  mset.insert({ A[0], A[1] });
  for ( size_t k = 2; k < N; ++k )
  {
    mset.insert(A[k]);
    auto it = next(mset.begin(), 2);
    cout << *it << '\n';
  }
}
