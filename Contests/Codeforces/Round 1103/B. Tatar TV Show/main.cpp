#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N, K; cin >> N >> K;
    
    string s; cin >> s;
    
    for ( size_t i = 0; i < N-K; ++i )
    {
      if ( s[i] != s[i+K] )
      {
        s[i] = '0', s[i+K] = '1';
      }
      else
        s[i] = s[i+K] = '0';
    }
    
    bool pos = true;
    for ( size_t i = 0; i < N; ++i )
    {
      if ( s[i] == '1' )
      {
        pos = false;
        break;
      }
    }

    cout << ( pos ? "YES\n" : "NO\n" );
  }
  return 0;
}
