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
    size_t zeros = 0;
    for ( auto & a : A )
      cin >> a, zeros += ( 0 == a ? 1 : 0 );

    if ( zeros != 1)
    {
      cout << "YES" << '\n';
      bool inA = false;
      for ( size_t i = 0; i < N; ++i )
      {
        if ( 0 == A[i] )
        {
          cout << ( inA ? "B" : "A" );
          inA = true;
        }
        else
          cout << "C";
      }
    }
    else
      cout << "NO";
      
    cout << '\n';
  } 
  return 0;
}
