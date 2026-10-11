#include <bits/stdc++.h>

using namespace std;

string solve(void);

int main(void)
{
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    cout << solve();
  } 
  return 0;
}


bool win(string S)
{
  size_t L = 0, R = S.length() - 1;
  while ( L < S.length() ) 
    if ( S[L] == '0')
      ++L;
    else
      break;
  
  while ( R > 0 )
    if ( S[R] == '1')
      --R;
    else
      break;
  
  size_t cnt = 0;
  for ( size_t i = L+1; i <= R; ++i )
  {
    if ( i == L+1 )
      cnt = 1;
    if ( S[i] == S[i-1] )
      ++cnt;
    else
    {
      if ( cnt % 2 )
        return true;
      else
        cnt = 1;
    }
  }

  return cnt%2;
}

string solve(void)
{
  size_t N; cin >> N;
  string S; cin >> S;


  return ( win(S) ? "Alice\n" : "Bob\n" );
}

