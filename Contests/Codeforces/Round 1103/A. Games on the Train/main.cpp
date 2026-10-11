#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N; cin >> N;

    vector<int8_t> H(N);
    int8_t maxh = 0, minh = INT8_MAX;
    for ( int8_t &h : H )
    {
      cin >> h;
      maxh = max(maxh, h);
      minh = min(minh, h);
    }
    
    cout << maxh - minh + 1 << '\n';
  }

  return 0;
}
