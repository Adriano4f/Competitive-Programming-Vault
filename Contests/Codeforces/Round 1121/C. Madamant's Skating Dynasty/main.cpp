#include <bits/stdc++.h>

using namespace std;

constexpr size_t MOD = 998244353;

size_t pou(int64_t n)
{
  if ( n <= 0 )
    return 1;

  return 2*pou(n-1) % MOD;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N; cin >> N;
    vector<size_t> A(N);
    size_t sum = 0;
    for ( auto & a : A )
      cin >> a, sum += a;

    sort(A.begin(), A.end());

    size_t fact = 1;
    vector<size_t> inv(N);
    inv[min(N-1, size_t(1))] = 1;
    for ( size_t i = 2; i < N; ++i )
    {
      fact *= i;
      fact %= MOD;

      inv[i] = MOD - (MOD/i) * inv[MOD%i] % MOD;
    }
    size_t ans = 0;
    for ( size_t i = 0; i < N-1; ++i )
    {
      sum -= A[i];
      size_t m = (N-1)-i;
      size_t tmp = (sum - A[i]*m)%MOD ;
      ans += (((tmp*fact)%MOD)*inv[m])%MOD;
      ans %= MOD;
    }

    cout << ans << '\n';
  }
  return 0;
}
