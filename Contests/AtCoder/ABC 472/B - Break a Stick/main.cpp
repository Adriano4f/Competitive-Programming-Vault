#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  size_t N; cin >> N;

  vector<int32_t> L(1);
  cin >> L[0];
  for ( size_t i = 0; i < N-1; ++i )
  {
    int32_t input; cin >> input;
    L.emplace_back( input + L.back() );
  }

  int32_t ans = INT32_MAX;
  for ( size_t i = 0; i < N; ++i )
  {
    ans = min( ans, abs(L[i] - (L.back() - L[i])) );
  }

  cout << ans;
  return 0;
}
