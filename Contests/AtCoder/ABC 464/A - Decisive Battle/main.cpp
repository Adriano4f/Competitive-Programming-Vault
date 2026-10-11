#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  string S; cin >> S;
  int32_t w, e = w = 0;
  for ( size_t i = 0; i < S.length(); ++i )
  {
    switch ( S[i] )
    {
      case 'E':
        ++e;
        break;

      case 'W':
        ++w;
        break;
    }
  }

  cout << ( w > e? "West" : "East" );
  return 0;
}
