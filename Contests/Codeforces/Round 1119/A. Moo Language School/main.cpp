#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N, K, ans = 0; cin >> N >> K;
    string S; cin >> S;
    bool last = true;
    for ( size_t i = 0; i < N; ++i )
    {
      last = min(last, bool(S[i] == '1'));

      if ( 0 == (i+1) % K )
        ans += last, last = bool(S[i+1] == '1');
    }
    cout << ans << '\n';
  }
  return 0;
}
