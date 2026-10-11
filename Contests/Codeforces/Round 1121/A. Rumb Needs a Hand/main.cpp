#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N; cin >> N;
    size_t last = SIZE_MAX;
    bool pos = true;
    for ( size_t i = 1; i <= N; ++i )
    {
      size_t input; cin >> input;

      if ( input != i )
      {
        if ( last < input )
          pos = false;
        else
          last = input;
      }
    }

    cout << ( pos ? "YES\n" : "NO\n" );
  }
  return 0;
}
