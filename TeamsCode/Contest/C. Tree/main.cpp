#include <bits/stdc++.h>

using namespace std;

vector<bool> visited;
vector<uint64_t> A;
vector<vector<size_t>> adj;

size_t dfs( size_t u, const size_t & K )
{
  visited[u] = true;
  
  size_t sum = 0;
  bool pos = false;
  for ( auto & v : adj[u] )
  {
    if ( visited[v] )
      continue;
    
    size_t tmp = dfs( v, K );
    
    if ( tmp != K )
      sum += tmp;
    else
      pos = true;
    
  }

  visited[u] = false;

  return ( 0 == A[u] + sum && pos ? K : A[u] + sum );
}

int main(void)
{
  size_t N; cin >> N;
  A.resize(N), adj.resize(N), visited.resize(N);
  for ( auto & a : A )
    cin >> a;

  for ( size_t i = 0; i < N-1; ++i )
  {
    size_t u, v; cin >> u >> v, --u, --v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  
  size_t Q; cin >> Q;

  while ( Q-- )
  {
    size_t K; cin >> K;
    cout << ( dfs(0, K) != K ? "NO\n" : "YES\n" );
  }

  return 0;
}
