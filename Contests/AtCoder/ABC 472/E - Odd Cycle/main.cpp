#include <bits/stdc++.h>

using namespace std;

vector < vector < size_t > > adj;

vector<size_t> ans;
vector<int64_t> idx;
vector<bool> visited;

bool dfs( size_t u, size_t parent, vector<size_t> &path)
{
  idx[u] = (int64_t)path.size();
  path.emplace_back(u);
  
  for ( const size_t & v : adj[u] )
  {
    if ( visited[v] || v == parent )
      continue;

    if ( -1 != idx[v] && ((int64_t)path.size() - idx[v])%2 )
    {
      ans = vector<size_t>(path.begin() + (int64_t)idx[v], path.end());
      return true;
    }

    if ( -1 == idx[v] && dfs( v, u, path) )
      return true;
  }

  visited[u] = true;
  path.pop_back();
  idx[u] = -1;
  return false;
}

int main(void)
{
  size_t tc; cin >> tc;
  while ( tc-- )
  {
    ans.clear();
    size_t N, M; cin >> N >> M;
    adj.assign(N, vector<size_t>()), idx.assign(N, -1), visited.assign(N, false);
    for ( size_t i = 0; i < M; ++i )
    {
      size_t u, v; cin >> u >> v, --u, --v;
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }
    
    vector<size_t> buf;
    bool pos = dfs(0, 0, buf);
  
    if ( !pos )
    {
      cout << -1 << '\n'; 
      continue;
    }
    else
    {
      cout << ans.size() << '\n';
      for ( const size_t & a : ans )
        cout << a+1 << ' ';
      cout << '\n';
    }
  }

  return 0;
}
