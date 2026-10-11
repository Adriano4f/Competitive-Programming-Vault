#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N, M; cin >> N >> M;
    set<char> S;
    bool pos = true;
    for ( size_t i = 0; i < N; ++i )
    {
      string input; cin >> input;
      S.insert(input[0]);
    }
    for ( size_t i = 0; i < M; ++i )
    {
      string input; cin >> input;
      for ( size_t j = 0; j < input.length(); ++j )
      {
        if ( !S.count((char)tolower(input[j])) )
          pos = false;
      }
    }

    cout << ( pos ? "YES\n" : "NO\n" );
  }
  return 0;
}
