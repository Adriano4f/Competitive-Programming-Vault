#include <bits/stdc++.h>

using namespace std;

size_t N;
vector< unordered_map<size_t, size_t> > memo;
vector< pair<size_t, bool> > H;

int64_t V( pair<size_t, bool> p, size_t _T )
{
  int64_t T = int64_t(_T);
  return int64_t(p.first) + T - 2*T*int64_t(p.second);
}

size_t dp(size_t i, size_t T)
{
  if ( i >= N-1 )
    return 0;
  
  if ( memo[i].count(T) )
    return memo[i][T];

  size_t dif = size_t( abs( V(H[i], T) - V(H[i], T)) );
  int64_t v1 = V(H[i], T), v2 = V(H[i+1], T);

  if ( (v1 > v2 && H[i].second && !H[i+1].second)
          || (v1 < v2 && !H[i].second && H[i+1].second)
          || (v1 == v2) )
      memo[i][T] = dp(i+1, T) + dif;
  else
    memo[i][T] = dp(i+1, T) + dif,
    memo[i][T] = max(memo[i][T], dp(i+1, T + dif));

  return memo[i][T];

}

int main(void)
{
  cin >> N;
  H.resize(N);
  for ( size_t i = 0; i < N; ++i )
  {
    cin >> H[i].first;
    char in; cin >> in;
    H[i].second = ( in == 'D');
  }
  
  cout << dp(0, 0);
  return 0;
}
