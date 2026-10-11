#include <bits/stdc++.h>

using namespace std;

void solve(void);

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    solve();
  } 
  return 0;
}

vector < vector < size_t > > adj;
vector < size_t > sz;
vector < size_t > A;

size_t dfs( size_t v = 0, size_t parent = 0)
{
  size_t cnt = 0;
  for ( size_t i = 0; i < adj[v].size(); ++i )
  {
    if ( adj[v][i] == parent )
      continue;
    cnt += dfs(adj[v][i], v);
  }

  sz[v] = cnt + 1;
  return sz[v];
}

void solve(void)
{
  size_t N; cin >> N;

  adj.assign(N, vector<size_t>()), A.resize(N), sz.assign(N, 0);
  for ( size_t & a : A )
    cin >> a;

  for ( size_t i = 0; i < N - 1; ++i )
  {
    size_t u, v; cin >> u >> v, --u, --v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  dfs();

  int64_t ans = 0;
  for ( size_t i = 0; i < N; ++i )
  {
    size_t n = sqrt(A[i]);
    if ( n*n == A[i] )
    {
      size_t idx = -1;
      for ( size_t j = 0; j < adj[i].size(); ++j )
      {
        if ( sz[adj[i][j]] > sz[i] )
        {
          idx = j;
          break;
        }
      }
      
      size_t ourN = N-1;
      size_t sum = N-1;
      size_t product = sum*sum;
      for ( size_t j = 0; j < adj[i].size(); ++j )
      {
        size_t subtree = sz[adj[i][j]];
        if ( idx == j )
          subtree = N - sz[i];
        
        product -= subtree*subtree;
        ourN -= subtree;
        ans += subtree*ourN;
      }

      product >>= 1;
      for ( size_t j = 0; j < adj[i].size(); ++j )
      {
        size_t subtree = sz[adj[i][j]];
        if ( idx == j )
          subtree = N - sz[i];
        
        sum -= subtree;
        product -= subtree*sum;
        
        ans += subtree*product;
      }

    }
  }
  cout << ans << '\n';
}