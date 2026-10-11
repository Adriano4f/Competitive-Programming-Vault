#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N, K, M; cin >> N >> K >> M;

    if ( K > M )
    {
      cout << "NO\n";
      continue;
    }
  
    vector<size_t> A(N, 1);
    size_t last = 0;
    for ( size_t i = 0; i < N; ++i )
    {
      if ( i - last + 1 == K )
        A[i] = M - K + 1;
    }

    cout << "YES\n";
    for ( const size_t & a : A )
      cout << a << ' ';
    
    cout << '\n';
  } 
  return 0;
}
