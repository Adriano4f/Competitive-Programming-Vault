#include <bits/stdc++.h>

using namespace std;

string solve(void);

vector<int> A;
vector< vector<size_t> > adj;
size_t ans;

pair<int64_t, bool> dfs( const size_t u, const size_t p )
{
  if ( 1 == adj[u].size() && 0 != u )
  {
    ++ans;
    return make_pair(A[u], false);
  }

  int64_t sum = 0, cnt = 0;
  for ( size_t & v : adj[u] )
  {
    
    if ( p == v )
      continue;

    auto tmp = dfs(v, u);
    sum += tmp.first;
    if ( ( adj[v].size() == 1 && 0 == A[v] ) || tmp.second )
      ++cnt;
  }

  if ( A[u] == 0 )
  {
    if ( 0 < sum )
      A[u] = -1;
    else
      A[u] = 1;
  }

  sum += A[u];

  if ( cnt )
  {
    auto buf = sum;
    if ( 0 < sum )
      sum -= min(sum, cnt);
    else
      sum += min(abs(sum), cnt);

    cnt -= min(abs(buf), cnt);
  }

  auto pos = cnt - (cnt/2)*2;
  sum += pos;
  ans += size_t(abs(sum));
  return make_pair( sum - pos, bool(cnt - (cnt/2)*2) );
}

int main(void)
{
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N; cin >> N;
    ans = 0;
    A.resize(N);
    for ( auto & a : A )
      cin >> a;
    
    adj.assign(N, vector<size_t>());
    for ( size_t i = 0; i < N-1; ++i )
    {
      size_t u, v; cin >> u >> v, --u, --v;
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }

    dfs(0, 0);
    
    cout << ans << '\n';
  } 
  return 0;
}
