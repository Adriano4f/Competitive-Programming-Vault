#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  size_t N; cin >> N;
  vector<int64_t> A(N);
  int64_t ans = 0;
  for ( size_t i = 0; i < N; ++i )
    cin >> A[i], ans += ( 0 == i%2 ? A[i] : 0 );

  cout << ans;
  return 0;
}
