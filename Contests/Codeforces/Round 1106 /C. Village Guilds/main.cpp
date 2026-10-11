#include <bits/stdc++.h>

using namespace std;

size_t N;
vector < vector < size_t > > adj;
size_t ans = 0;

size_t function_that_computes_degree_over_subtree_and_returns_it(size_t idx = 0)
{
  if ( adj[idx].empty() )
    return 1;

  vector<size_t> degrees;
  for ( size_t i = 0; i < adj[idx].size(); ++i )
  {
    degrees.emplace_back(function_that_computes_degree_over_subtree_and_returns_it(adj[idx][i]));
  }
  sort(degrees.begin(), degrees.end(), greater<size_t>());

  if ( adj[idx].size() > 1 )
    ans += min(degrees[0], degrees[1]);
  
  return degrees[0] + 1;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    cin >> N;
    adj.assign(N, vector<size_t>());
    
    for ( size_t i = 1; i < N; ++i )
    {
      size_t p; cin >> p, --p;
      adj[p].emplace_back(i);
    }
    
    ans = N;
    size_t waste = function_that_computes_degree_over_subtree_and_returns_it();
    cout << ans << '\n';

  } 
  return 0;
}
