#include <bits/stdc++.h>

using namespace std;

constexpr int32_t maxT = 1'000'000'000;

vector<vector<pair<size_t, size_t>>> BL;
vector<size_t> A;

vector<int32_t> decompose( int32_t n );
pair<size_t, size_t> populate(size_t power, size_t i )
{ // populate binary lifts
  auto to_ret = BL[ BL[i].back().first ][power-1];
  return make_pair(to_ret.first, to_ret.second + BL[i].back().second);
}

size_t query( size_t i, vector<int32_t> &v );

int main(void)
{
  size_t N, Q; cin >> N >> Q;
  BL.resize(N), A.resize(N);
  for ( size_t i = 1; i <= N; ++i )
    cin >> A[i-1], BL[i-1].emplace_back( make_pair(A[i-1]-1, i));

  size_t powa = 1;
  while ( (1 << powa) <= maxT )
  {
    for ( size_t i = 0; i < N; ++i )
      BL[i].emplace_back(populate( powa, i ));

    ++powa;
  }


  while ( Q-- )
  {
    int32_t T; size_t B; cin >> T >> B;
    vector<int32_t> d = decompose( T );

    cout << query(--B, d) << '\n';
  }
  return 0;
}

vector<int32_t> decompose( int32_t n )
{
  vector<int32_t> to_ret;
  while ( n > 0 )
  {
    to_ret.emplace_back(__builtin_ctzl(n));
    n &= (n - 1);
  }
  return to_ret;
}

size_t query( size_t i, vector<int32_t> &v )
{
  size_t powa = v.back();
  v.pop_back();
  if ( v.empty() )
    return BL[i][powa].second;

  return query( BL[i][powa].first, v ) + BL[i][powa].second;
}
