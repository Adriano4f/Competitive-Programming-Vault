#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  size_t X, Y, L, R, A, B, ans = 0; cin >> X >> Y >> L >> R >> A >> B;
  for ( size_t i = A; i < B; ++i )
  {
    if ( L <= i && i < R )
      ans += X;
    else
      ans += Y;
  }

  cout  << ans << '\n';
  return 0;
}
