#include <bits/stdc++.h>

using namespace std;

string S;
vector<bool> discarded;
string computenewstr( void );

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N; cin >> N;
    cin >> S;
    bool changed = false, one = false;
    for ( size_t i = 0; i < N-1; ++i )
    {
      if ( S[i] != S[i+1] )
      {
        if (changed)
          one = true;
        else
          changed = true;
      }
      if ( one )
        break;
    }

    cout << (one || !changed? 1 : 2 ) << '\n';
  }
  return 0;
}

