#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N; cin >> N;
    vector< int > A(N);
    int64_t first = N, last = -1;
    for ( size_t i = 0; i < N; ++i )
    {
      cin >> A[i];
      if ( 0 != A[i] )
        first = min(int64_t(i), first),
        last = max(int64_t(i), last);
    }

    for ( size_t i = 0; i < N; ++i )
    {
      if ( i == first || i == last )
        cout << 1;
      else
        cout << ( -1 == A[i] ? 0 : A[i] );\
    
      cout << ( i == N-1? "\n" : " " );
    }
  }
  return 0;
}

