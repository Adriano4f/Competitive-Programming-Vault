#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  size_t N; cin >> N;
  size_t sum = 0;
  unordered_map<size_t, bool> alr;
  for ( size_t i = 0; i < N; ++i )
  {
    size_t in; cin >> in;
    if ( alr[in] )
      sum -= in, alr[in] = false;
    else
      sum += in, alr[in] = true;
  }
  cout << sum;
  return 0;
}
