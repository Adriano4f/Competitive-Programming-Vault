#include <bits/stdc++.h>

using namespace std;

vector<int16_t> A;
vector<vector< unordered_map<int64_t, int8_t>>> memo;
bool dp( bool last, int64_t sum, int64_t i = 1 );

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N; cin >> N;
    memo.assign(2, vector<unordered_map<int64_t, int8_t>>(N));
    A.resize(N);
    for ( int16_t & a : A )
      cin >> a;

    cout << ( dp((bool)(A[0] < 0), A[0]) ? "YES\n" : "NO\n" );
  }
  return 0;
}

bool dp( bool last, int64_t sum, int64_t i )
{
  if ( i >= memo[0].size() )
    return sum == 0;
  
  if ( memo[last][i].count(sum) )
    return memo[last][i][sum];
  
  int8_t & memcho = memo[last][i][sum];

  memcho = dp(A[i] < 0, sum + A[i], i+1);
  memcho = max(memcho, (int8_t)dp(A[i] > 0, sum - A[i] + 2*(last*2 - 1), i+1));
  return memcho;
}
