#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N; cin >> N;
    vector<size_t> A(N);
    size_t X = 0;
    for ( size_t & a : A )
      cin >> a, X ^= a;
    
    size_t count = 0;
    for ( const size_t & a : A )
      if ( (a^X) < a )
        ++count;

    if ( N == 1 )
      count = 0;

    cout << ( X || N == 1? count : 1 ) << '\n';
  }

  return 0;
}
