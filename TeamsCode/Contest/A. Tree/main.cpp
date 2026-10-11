#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  bool pos = true;


  char last, c1 = last = getchar();
  while ( EOF != c1 )
  {
    last = c1;
    c1 = getchar();
    if ( "O2" == string("" + last + c1) )
    {
      pos = true;
      break;
    }
    
    if ( ( 0 <= int(c1 - '0') && int(c1 - '0') < 10 ) )
      pos = false;
  }

  cout << ( pos ? "YES" : "NO" );
  return 0;
}
