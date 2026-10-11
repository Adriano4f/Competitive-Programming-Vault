#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  size_t N; cin >> N;
  string S, T; cin >> S >> T;
  for ( size_t i = 0; i < N; ++i )
    if ( '*' == T[i] )
      T[i] = S[i];

  cout << ( S == T ? "Yes" : "No" );
  return 0;
}
