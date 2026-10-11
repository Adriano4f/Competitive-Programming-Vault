#include <bits/stdc++.h>

using namespace std;

vector <size_t> A;
vector <size_t> B;

vector<vector<int64_t>> memo;
int64_t dp( size_t i = 0, bool changed = 0, bool cons = 0 );

int main(void)
{
  size_t N, M; cin >> N >> M;
  memo.resize(2, vector<int64_t>(N, -1));
  A.resize(N);
  for ( size_t & a : A )
    cin >> a;

  B.resize(N-1);
  for ( size_t & b : B )
    cin >> b;
  
  cout << dp();
  return 0;
}

int64_t dp( size_t i, bool changed, bool cons )
{
  if ( i >= memo[0].size() - 1 )
    return changed;
  
  if ( -1 != memo[changed][i] )
    return memo[changed][i];

  if ( ( (A[i] + A[i+1] + changed) % 2 ) != B[i] )
  {
    memo[changed][i] = dp(i+1, 1) + 1;
    if ( !changed && !cons )
     memo[changed][i] = min(memo[changed][i], dp(i+1, 0) + 1);
  }
  else
    memo[changed][i] = dp(i+1, 0, 1);
  
  return memo[changed][i];
}
