#include <bits/stdc++.h>

using namespace std;


int main(void)
{
  ios_base::sync_with_stdio(false);

  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N; cin >> N;
    vector<size_t> A(N);
    
    for ( size_t &a : A )
      cin >> a, --a;
    
    vector< vector<bool> > pos(N, vector<bool>(N));
    for ( size_t i = 0; i < N; ++i ) 
    {
      vector<bool> visited(N);
      size_t mx = 0, mn = INT_MAX;
      for ( size_t j = i; j < N; ++j )
      {
        if ( visited[A[j]] )
          break;

        visited[A[j]] = 1;
        mx = max(mx, A[j]);
        mn = min(mn, A[j]);

        if ( mx - mn == j - i )
          pos[mn][mx] = true;
      }
    }

    size_t ans = 0;
    for ( size_t i = 1; i <= N/2; ++i )
    {
      for ( size_t j = 0; j + 2*i <= N; ++j )
      {
        if ( pos[j][j + i - 1] && pos[j + i][j + 2*i - 1])
          ans = max(ans, i); 
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
