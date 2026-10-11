#include <bits/stdc++.h>

using namespace std;

constexpr size_t mod = 998244353;

size_t powmod(size_t base, size_t e, size_t MOD = mod );


int main(void)
{
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t n, m, r, c; cin >> n >> m >> r >> c;
    cout << powmod(2, m*r - m + n*c - n - (r-1)*(c-1)) << '\n'; 
  }

  return 0;
}

size_t powmod(size_t base, size_t e, size_t MOD)
{
  if ( e == 0 )
    return 1;
  
  size_t res = powmod(base, e/2);
  res *= res, res %= MOD;

  if ( e%2 )
    res *= base, res %= MOD;

  return res % MOD;
}