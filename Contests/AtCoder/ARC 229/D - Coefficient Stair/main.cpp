#include <bits/stdc++.h>

using namespace std;

size_t N, K;
vector< vector<size_t> > ans;
vector< size_t > tmp;

void dp(size_t i, size_t left)
{
  if ( i == 1  )
  {
    tmp[i-1] = left;
    ans.emplace_back(tmp);
    return;
  }

  for ( size_t x = 0; x <= left/i; ++x )
  {
    tmp[i-1] = x;
    dp(i-1, left - x*i);
  }
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin >> N >> K;
  tmp.resize(N);
  dp(N, K);
  sort(ans.begin(), ans.end());

  for ( auto const & v : ans )
  {
    for ( size_t i = 0; i < N; ++i )
    {
      cout << v[i] << ( i < N-1 ? " " : "" );
    }
    cout << '\n';
  }
  return 0;
}
