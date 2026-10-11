#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  string s; cin >> s;
  cout << s << ( s.back() == 'e' ? "r" : "er" );
  return 0;
}
