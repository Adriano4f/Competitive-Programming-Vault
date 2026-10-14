#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  size_t N, Q; cin >> N >> Q;
  vector<size_t> L(N), R(N), Rp(N), Ls(N);
  for ( size_t i = 1; i < N; ++i )
    cin >> L[i];
  for ( size_t i = 0; i < N-1; ++i )
    cin >> R[i];

  Rp[0] = 0;
  for ( size_t i = 1; i < N-1; ++i )
  {
    if ( R[i] < R[Rp[i-1]] )
      Rp[i] = i;
    else
      Rp[i] = Rp[i-1];
  }
  
  Ls.back() = Ls.size()-1;
  for ( size_t i = N-2; i > 0; --i )
  {
    if ( L[i] < L[Ls[i+1]] )
      Ls[i] = i;
    else
      Ls[i] = Ls[i+1];
  }

  while ( Q-- )
  {
    size_t s, t; cin >> s >> t, --s, --t;\
    if ( 0 == s )
    {
      cout << R[0] << '\n';
      continue;
    }
    else if ( N-1 == s )
    {
      cout << L.back() << '\n';
      continue;
    }
    
    auto r = Rp[s-1], l = Ls[s+1];
    size_t ans = 0;
    if ( s > t )
    {
      ans = min(
        R[s] + L[l],
        L[s]
      );
    }
    else
    {
      ans = min(
        L[s] + R[r],
        R[s]
      );
    }
    
    cout << ans << '\n';
  }
  return 0;
}
