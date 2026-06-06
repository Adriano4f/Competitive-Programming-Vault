#include <bits/stdc++.h>

using namespace std;

vector< pair<int64_t, int64_t> > t;

bool
isInter(int64_t i, int64_t j)
{
  return (t[i].first <= t[j].second && t[i].second >= t[j].second) || (t[j].first <= t[i].second && t[j].second >= t[i].second) || 
    (t[i].second >= t[j].first && t[i].first <= t[j].first) || (t[j].second >= t[i].first && t[j].first <= t[i].first) ;
}

int32_t main(void)
{
  int32_t N; cin >> N;
  for (int i = 0; i < N; ++i )
  {
    int64_t T, l, r; cin >> T >> l >> r;
    switch (T)
    {
      case 1:
        t.emplace_back( make_pair(l, r) );
        break;
      case 2:
        t.emplace_back( make_pair(l, r-1) );
        break;
      case 3:
        t.emplace_back( make_pair(l+1, r) );
        break;
      case 4:
        t.emplace_back( make_pair(l+1, r-1) );
        break;
    }
  }

  int32_t ans = 0;
  for (int i = 0; i < N-1; ++i )
    for (int j = i+1; j < N; ++j )
    {
      if ( isInter(i, j) )
        ++ans;
    }

  cout << ans;
}