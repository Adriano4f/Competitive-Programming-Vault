#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N; cin >> N;

    uint16_t last = INT16_MAX;
    uint32_t sum = 0;
    for ( uint8_t i = 0; i < N; ++i )
    {
      uint16_t in; cin >> in;
      last = min(last, in);
      sum += (uint32_t)last;
    }
    
    cout << sum << '\n';
  }

  return 0;
}
