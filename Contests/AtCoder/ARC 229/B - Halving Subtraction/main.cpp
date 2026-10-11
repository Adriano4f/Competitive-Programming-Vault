#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  size_t tc; cin >> tc;
  while ( tc-- )
  {
    size_t N; cin >> N; 
    vector<size_t> A(N);
    for ( auto & a : A )
      cin >> a;
    
    reverse(A.begin(), A.end());

    vector<size_t> B(N);
    B[0] = A[0];
    bool pos = true;
    size_t nequal = 0;
    int64_t ans = 0;
    for ( size_t i = 1; i < N; ++i )
    {
      B[i] = A[i];
      if ( A[i]/2 == B[i-1] )
      {
        if ( nequal || A[i] < A[i-1] )
        {
          pos = false;
          break;
        }
        else
          continue;
      }
      else
        ++nequal;
      
      B[i] = B[i-1]*2 + A[i]%2;

      auto diff1 = A[i-1] - B[i-1], diff2 = A[i] - B[i];
      diff1 /= (1 << (nequal-1)), diff2 /= (1 << nequal);
      if ( diff1 > diff2 )
      {
        pos = false;
        break;
      }

      for ( size_t j = 0; i+j < N; ++j )
      {
        A[i+j] -= diff1*(1 << (nequal + j));
      }
      --nequal;
      ans += int64_t(diff1);
    }

    cout << ( pos ? ( A.back() ? ans + 1 : ans ) : -1 ) << '\n';
  }
  return 0;
}
