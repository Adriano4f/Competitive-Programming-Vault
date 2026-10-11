#include "festival.h"
#include <bits/stdc++.h>

using namespace std;

vector<int> max_coupons(int A, vector<int> P, vector<int> T)
{
  vector<vector<pair<int, int>>> C(4);

  for ( size_t i = 0; i < P.size(); ++i )
    C[T[i]-1].emplace_back( make_pair(P[i], i) );

  sort(C[0].begin(), C[0].end(), greater< pair<int, int> >());
  sort(C[1].begin(), C[1].end(), greater< pair<int, int> >());
  sort(C[2].begin(), C[2].end(), greater< pair<int, int> >());
  sort(C[3].begin(), C[3].end(), greater< pair<int, int> >());

  vector<int> R;

  while ( A > 0 )
  {
    pair<int, int> next = {-1, -1};
    for ( size_t i = 0; i < 4; ++i )
    {
      if ( C[i].empty() || C[i].back().first > A )
        continue;

      const int & c = C[i].back().first;
      int newA = (A - c) * (i + 1);
      if ( next.second < newA )
        next.first = i, next.second = newA;
    }

    if ( next == make_pair(-1, -1) )
      break;

    R.emplace_back( C[ next.first ].back().second );
    A = next.second;

    C[ next.first ].pop_back();
    
  }

  return R;
}
