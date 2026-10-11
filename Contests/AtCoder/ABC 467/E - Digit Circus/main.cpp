// PENDING
// Reason: skeleton / reads input but produces no output or result
// Next step: implement the solution and add the required output

#include <bits/stdc++.h>

using namespace std;

constexpr int32_t MOD = 998244353;

struct large
{
  string val;

  size_t operator/ ( const size_t & div ) const
  {
    size_t result = 0;
    size_t mod = MOD*div;

    for ( const char & n : val )
    {
      result = (result*10 + (n-'0')) % mod;
    }

    return result/div;
  }

};

int main(void)
{
  large N; cin >> N.val;
  size_t multiples = N / size_t(3);

  return 0;
}
