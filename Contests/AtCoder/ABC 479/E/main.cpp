#include <bits/stdc++.h>

using namespace std;

vector< vector<size_t> > adj;
vector< pair<size_t, size_t> > edges;
vector<int64_t> entry, exiT, tree, parent;

void dfs( size_t u, size_t p )
{
  parent[u] = (int64_t)p;

  static size_t t = 0;
  entry[u] = (int64_t)t;
  tree.emplace_back(u);
  t += 1;

  for ( auto const &v : adj[u] )
    if ( v != p )
      dfs(v, u);
  
  exiT[u] = (int64_t)t - 1;
}

int main(void)
{
  size_t N; cin >> N;
  adj.resize(N);
  parent.resize(N), entry.resize(N), exiT.resize(N);
  
  for ( size_t i = 0; i < N-1; ++i )
  {
    size_t A, B; cin >> A >> B, --A, --B;
    adj[A].emplace_back(B);
    adj[B].emplace_back(A);

    edges.emplace_back(A, B );
  }

  dfs(0, 0);

  vector<int64_t> diff(N+2, 0);
  vector<int64_t> ans(N+2, 0);
  for ( size_t i = 0; i < N-1; ++i )
  {
    auto u = edges[i].first, v = edges[i].second;
    if ( v == (size_t)parent[u] )
      swap(u, v);

    assert( 0 <= entry[v] && entry[v] < (int64_t)N
      && 0 <= exiT[v] && exiT[v] < (int64_t)N 
      && entry[v] <= exiT[v] );


    auto const &idx1 = (size_t)entry[v],
    &idx2 = (size_t)exiT[v];
    if ( exiT[v] - entry[v] + 1 > (int64_t)N/2  )
    {
      diff[idx1] += int64_t(i+1);
      diff[idx2+1] -= int64_t(i+1);
    }
    else
    {
      diff[idx1] -= int64_t(i+1);
      diff[idx2+1] += int64_t(i+1);
      diff[0] += int64_t(i+1);
      diff.back() -= int64_t(i+1);
    }
  }

  ans[0] = diff[0];
  for ( size_t i = 1; i <= N; ++i )
  {
    ans[i] += ans[i-1] + diff[i];
  }


  for ( size_t i = 0; i < N; ++i )
  {
    cout << ans[(size_t)entry[i]] << ' ';
  }
  return 0;
}
