#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t X, Y; cin >> X >> Y;
    cout << ( X % Y ? "NO\n" : "YES\n" );
  }
  return 0;
}
