#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  string S; cin >> S;
  for ( size_t i = 0; i < S.length(); ++i )
    if ( S[i] != 'A' )
      S[i] = '.';

  cout << S;
  return 0;
}
