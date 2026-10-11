#include <bits/stdc++.h>

using namespace std;

size_t pow_s(size_t n)
{
  if ( n == 0 )
    return 1;

  return pow_s(n-1)*10;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    string N; cin >> N;
    cout << pow_s(N.size()) + 1 << '\n';
  } 
  return 0;
}
