#include <bits/stdc++.h>

using namespace std;


int main(void)
{
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N, D; cin >> N >> D;
    vector < int64_t > A(N*3), pf ={0};
    pf.reserve((N+1)*3);
    

    for ( size_t i = 0; i < N*3; ++i )
    {
      if ( i < N )
        cin >> A[i], A[i+N] = A[i+N*2] = A[i];

      pf.emplace_back(pf.back() + A[i]);
    }


    int64_t ans = 0;
    for ( size_t i = 0; i < N; ++i )
    {
      ans += max( int64_t(0), A[i]*2*(int64_t)D + A[i] - (pf[i+N+D+1] - pf[i+N-D]) );
      
    }
    cout << ans << '\n';
  }
  
  return 0;
}
