#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t X, Y, K; cin >> X >> Y >> K;
    size_t cnt = 0;
    if ( Y % K || Y / K != X  )
      while ( ++cnt )
      {
        if ( 0 == Y % K && Y / K == X )
          break;
        else
          X /= K;

        cout << "X Y: " << X << ' ' << Y << '\n';
      }

    cout << cnt << '\n';
  }

  return 0;
}
