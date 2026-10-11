#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N; cin >> N;
    for ( size_t i = N; i > 0; --i )
      cout << i << ' ';

    cout << '\n';
  }
  return 0;
}
