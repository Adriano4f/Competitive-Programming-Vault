#include <bits/stdc++.h>
 
using namespace std;
 
size_t N, M;
int32_t K, B;
int64_t memo[1001][10002][2];
 
struct Technique
{
  int32_t t, h, c;
};
 
vector<Technique> T;
 
int64_t dp(int last, size_t m, size_t i);
 
int main(void)
{
  ios_base::sync_with_stdio(false);
 
  int32_t tc; cin >> tc;
  while (tc--)
  {
      cin >> N >> K >> M >> B;
      memset(memo, -1, sizeof(memo));
 
      T.resize(N);
      for ( Technique &t : T )
      {
          cin >> t.t >> t.h >> t.c;
      }
      sort( T.begin(), T.end(), [](const Technique &a, const Technique &b) { return (a.c < b.c); });
      cout << dp(-1, M, 0) << '\n';
  }
  return 0;
}
 
int64_t dp(int last, size_t m, size_t i)
{
  if (i >= N || m <= 0)
      return 0;
 
  bool l = (last == T[i].c);
  if ( -1 != memo[i][m][l] )
      return memo[i][m][l];
 
  if ( m >= (size_t)T[i].t )
  {
    int64_t sum = T[i].h + (last != -1 && !l ? B : 0);
    memo[i][m][l] = dp(T[i].c, m - (size_t)T[i].t, i+1) + sum;
  }
  
  memo[i][m][l] = max(memo[i][m][l], dp(last, m, i+1));
 
  return memo[i][m][l];
}
