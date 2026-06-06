#include <bits/stdc++.h>

using namespace std;


int32_t main(void)
{
  int64_t X, A, D, N; cin >> X >> A >> D >> N;

  int64_t l = 0, r = N-1, res = 0;
  while ( l <= r )
  {
    int64_t mid = l + (r-l)/2;

    if ( A + D*mid <= X )
    {
      l = mid+1;
      res = mid;
    }
    else
    {
      r = mid-1;
      res = mid;
    }
    
  }

  cout << min(X - (A+ D*res), X - (A+ D*(res+1)));
}
