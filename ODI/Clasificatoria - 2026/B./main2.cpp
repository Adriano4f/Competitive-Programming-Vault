// THIS WORKS FOR A HALF OF THE SCORE

#include <bits/stdc++.h>

using namespace std;

struct package
{
  int64_t w = 0, v = 0;
};

int64_t W;
size_t N;
vector<package> P;
vector<vector<int64_t>> memo;

int64_t dp(size_t i, int64_t w)
{
  
  if ( w <= 0 || i >= N )
    return 0;

  size_t w2 = (size_t)w;
  if ( memo[i][w2] )
  {
    return memo[i][w2];
  }

  package cur = P[i];
  memo[i][w2] = max(
    (w - cur.w >= 0? dp(i+1, w-cur.w) + cur.v : 0),
    dp(i+1, w)
  );

  return memo[i][w2];
}

int32_t main(void)
{
  cin >> W >> N;

  P.resize(N);
  memo.resize(N, vector<int64_t>((size_t)W+1, 0));

  for ( package &p : P )
  {
    cin >> p.w >> p.v;
  }

  cout << dp(0, W);
  return 0;
}
