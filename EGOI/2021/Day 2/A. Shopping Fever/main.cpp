#include <bits/stdc++.h>

using namespace std;

uint32_t N, Q, dis;
vector<uint32_t> P;

uint64_t dp(void);

int32_t main(void)
{
  cin >> N >> Q;
  dis = (100-Q);

  P.resize(N);
  for ( auto &p : P )
    cin >> p;
  
  sort(P.begin(), P.end());

  cout << dp(); 
  return 0;
}

uint64_t dp(void)
{
  vector<uint64_t> memo(N);

  memo[0] = dis*P[0]/100;

  if ( N > 1 )
    memo[1] = dis*P[1]/100 + memo[0];
    
  if ( N > 2 )
    memo[2] = min(
      dis*P[2]/100 + memo[1], 
      (uint64_t)P[2]+P[1]
    );

  for ( uint32_t i = 3; i < N; ++i )
  {
    memo[i] = dis*P[i]/100 + memo[i-1];
    memo[i] = min(
      memo[i],
      P[i] + P[i-1] + memo[i-3]
    );
  }
  
  return memo[N-1];
}
