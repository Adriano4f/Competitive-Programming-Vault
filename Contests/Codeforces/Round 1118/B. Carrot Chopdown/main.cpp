#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N, M; cin >> N >> M;
    vector<int32_t> A(N);
    unordered_map<int32_t, size_t> f;
    for ( auto & a : A )
      cin >> a, ++f[a];

    sort(A.begin(), A.end());
    size_t ans = 0;
    for ( int32_t i = 1; size_t(i) <= M; ++i )
    {
    }

    cout << ans << '\n';

  }
  return 0;
}
