#include <bits/stdc++.h>

using namespace std;

int32_t X;

map<int32_t, map<int32_t, int32_t> > memo;

int32_t dp(int32_t a, int32_t b);

int main(void)
{
  ios_base::sync_with_stdio(false);

  int32_t tc; cin >> tc;

  while (tc--)
  {
    int32_t A, B; cin >> A >> B >> X;
    memo = map<int32_t, map<int32_t, int32_t> >();
    
    cout << dp(A, B) << '\n';
    
  }
  return 0;
}

int32_t dp(int32_t a, int32_t b)
{
  if ( a == b )
    return 0;
  
  int32_t tmp = a;
  a = max(a, b);
  b = min(b ,tmp);

  if ( memo[a].count(b) )
    return memo[a][b];


  memo[a][b] = dp(a/X, b) + 1;
  memo[a][b] = min( memo[a][b], abs(a-b) );

  return memo[a][b];
}
