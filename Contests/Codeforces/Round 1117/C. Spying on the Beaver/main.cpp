#include <bits/stdc++.h>

using namespace std;

vector< vector<size_t> > adj;
vector<bool> damned;
vector<size_t> ans;

bool dfs(size_t i, bool found = 0)
{
  bool ret = damned[i];

  for ( auto & v : adj[i] )
  {
    ret = ret | dfs(v, ret | damned[i] | found); 
  }

  if ( damned[i] && found )
    ans.emplace_back(i);

  return ret;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N; cin >> N;
    adj.assign(N, vector<size_t>());
    ans.clear();

    for ( size_t i = 1; i < N; ++i )
    {
      size_t input; cin >> input, --input;
      adj[input].emplace_back(i);
    }

    size_t M; cin >> M;
    damned.assign(N, false);
    for ( size_t i = 0; i < M; ++i )
    {
      size_t input; cin >> input, --input;
      damned[input] = true;
    }

    dfs(0);
    
    cout << ans.size() << ' ';
    for ( auto & a : ans )
      cout << a+1 << ' ';
    
    cout << '\n';
  }
  return 0;
}

