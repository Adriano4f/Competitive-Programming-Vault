#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N; cin >> N;
    vector<size_t> C(N);

    for ( size_t & c : C )
      cin >> c;

    int8_t pos = 0;
    for ( size_t & c : C )
      if ( pos == true || c > 2 )
        pos = true;
      else if ( c == 2 && pos == -1 )
        pos = true;
      else if ( c == 2 )
        pos = -1;

    cout << ( pos == true ? "YES\n" : "NO\n" );
  }
  return 0;
}
