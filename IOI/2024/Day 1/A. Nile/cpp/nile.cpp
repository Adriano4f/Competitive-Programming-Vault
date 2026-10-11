#include "nile.h"
#include <bits/stdc++.h>

using namespace std;

struct article
{
  int w,a,b;

  bool operator< ( const article & other ) const 
  {
    return w < other.w;
  }

};

std::vector<long long> calculate_costs(std::vector<int> W, std::vector<int> A,
                                       std::vector<int> B, std::vector<int> E) {
  size_t N = W.size(), sum = 0;

  

  vector<article> F(N);
  for ( size_t i = 0; i < N; ++i )
    F[i] = {W[i], A[i], B[i]};
  
  sort(F.begin(), F.end());
  
  vector<int> D(N);
  for ( size_t i = 0; i < N; ++i )
    sum += F[i].b, D[i] = F[i].a - F[i].b;

  vector<long long> R;
  for ( const int &q : E )
  {
    vector<size_t> dp(N+1);
    dp[0] = 0;
    for ( size_t i = 1; i <= N; ++i )
    {
      dp[i] = dp[i-1] + D[i-1];
      if ( i > 1 && F[i-2].w - F[i-1].w <= q ) 
        dp[i] = min(dp[i], dp[i-2]);
      if ( i > 2 && F[i-3].w - F[i-1].w <= q )
        dp[i] = min(dp[i-1], dp[i-3] + D[i-2]);
    }
    
    R.emplace_back(sum + dp[N]);
  }
  return R;
}
