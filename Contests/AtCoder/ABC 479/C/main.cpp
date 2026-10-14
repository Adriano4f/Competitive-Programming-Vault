#include <bits/stdc++.h>

using namespace std;

vector< map<size_t, size_t> > memo;
vector<size_t> A, B;

uint64_t dp( size_t idx, size_t mask, size_t W )
{
  if ( idx >= memo.size() )
    return 0;

  if ( memo[idx].count(mask) )
    return memo[idx][mask];
  
  if ( W >= B[idx] )
  {
    memo[idx][mask] = max(memo[idx][mask], dp(idx+1, mask | (1 << idx), W-B[idx]) + A[idx]);
  }

  memo[idx][mask] = max(memo[idx][mask], dp(idx+1, mask, W));
  return memo[idx][mask];
}

int main(void)
{
  size_t N, W; cin >> N >> W;
  A.resize(N), B.resize(N), memo.resize(N);

  for ( size_t i =0; i < N; ++i )
    cin >> A[i] >> B[i];

  cout << dp(0, 0, W);
  return 0;
}
