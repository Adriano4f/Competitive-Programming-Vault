#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N; cin >> N;
    vector<int64_t> A(N);
    vector< pair<int64_t, int64_t> > B;
    for ( auto & a : A )
      cin >> a, B.emplace_back( ( a / 2 % 2 ? make_pair(a - (a/2)*2, abs((a - (a/2)*2) - 2)) : make_pair(abs((a - (a/2)*2) - 2), a - (a/2)*2) ) );
    
    size_t ans = 0;
    unordered_map<int64_t, size_t> fo, fe;
    for ( auto & [odd, even] : B )
    {
      ans = max( { ans, ++fo[odd], ++fe[even] } );
    }

    cout << ans << '\n';
  } 
  return 0;
}
