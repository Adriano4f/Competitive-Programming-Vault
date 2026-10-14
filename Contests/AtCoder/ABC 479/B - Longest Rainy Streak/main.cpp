#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  size_t N; cin >> N;
  string S; cin >> S;
  size_t ans = 0; size_t rainy = 0;
  for (  size_t i = 0; i < N; ++i )
  {
    auto &s = S[i];
    if ( 'S' == s )
      rainy = 0;
    else
      ++rainy, ans = max(ans, rainy);
  }
  
  cout << ans;
  return 0;
}
