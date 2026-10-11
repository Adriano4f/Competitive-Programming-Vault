#include <iostream>

using namespace std;

int main(void)
{
  string s; cin >> s;
  for ( size_t i = 0; i < s.length(); ++i )
  {
    if ( 0 <= s[i]-'0' && s[i]-'0' <= 9 )
      cout << s[i];
  }
  return 0;
}
