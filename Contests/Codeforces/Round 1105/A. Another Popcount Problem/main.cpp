#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    int64_t N, K; cin >> N >> K;
    int64_t count = 0, power = 1;
    do 
    {
      int64_t a = N/power;
      N -= (min(K, a) * power);
      count += min(K, a);
      power *= 2;
    } while( N >= power );
    cout << count << '\n';
  } 
  return 0;
}
