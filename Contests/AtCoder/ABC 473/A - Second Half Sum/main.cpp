#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  size_t N; cin >> N;
  size_t sum = 0;
  for ( size_t i = 1; i <= N; ++i )
  {
    size_t in; cin >> in;
    if ( N/2 < i )
      sum += in;
  }
  cout << sum;
  return 0;
}
