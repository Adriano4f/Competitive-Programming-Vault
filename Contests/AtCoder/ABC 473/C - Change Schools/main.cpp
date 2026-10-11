#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  size_t N, K; cin >> N >> K;
  vector< size_t > A(K);
  size_t maxk = 0, ans = 0;
  for ( size_t i = 0; i < N; ++i )
  {
    size_t in; cin >> in, ++A[--in];
    maxk = max(maxk, A[in]);
  }
  for ( size_t i = 0; i < K; ++i )
  {
    if ( A[i] + 1 >= maxk )
      ++ans;
  }

  cout << ans;
}

