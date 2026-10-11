#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N; cin >> N;
    vector < size_t > A(N), B(N);
    for ( size_t & a : A )
      cin >> a;
    for ( size_t & b : B )
      cin >> b;

    bool pos = true;
    for ( int64_t i = N-1; i >= 0; --i )
    {
      if ( i > 0 )
      {
        if ( A[i] > B[i] )
          A[i-1] += A[i]-B[i];
      }
      else
      {
          if ( A[i] > B[i] )
          {
            pos = false;
            break;
          }
      }
    }

    cout << ( pos ? "YES\n" : "NO\n" );
  } 
  return 0;
}
