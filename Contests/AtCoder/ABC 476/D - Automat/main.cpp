// PENDING
// Reason: does not compile — stray '+' after cin at line 15
// Next step: remove the '+' and verify the purchase simulation logic

#include <bits/stdc++.h>

using namespace std;

size_t calculate( const size_t left, vector<size_t> & bought )
{
  auto it = upper_bound(bought.begin(), bought.end(), left);

  return size_t( it - bought.begin() );
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  size_t N, M, K; cin >> N >> M >> K;+
  size_t X, Y; cin >> X >> Y;

  vector<size_t> F(N), D(M);
  for ( auto & f : F )
    cin >> f;
  for ( auto & d : D )
    cin >> d;

  sort(F.begin(), F.end());
  vector<size_t> bought(N);
  bought[0] = F[0];
  for ( size_t i = 1; i < N; ++i )
  {
    bought[i] = F[i] + bought[i-1];
  }

  sort(D.begin(), D.end());
  size_t ans = calculate(X + Y*K, bought);
  for ( size_t i = 0; i < M; ++i )
  {
    auto cost = (D[i] + K - 1)/K;

    if ( cost > Y )
      break;

    Y -= cost;
    X += cost*K - D[i];
    ans = max( ans, i+1 + calculate(X + Y*K, bought) );
  }
  cout << ans;
  return 0;
}
