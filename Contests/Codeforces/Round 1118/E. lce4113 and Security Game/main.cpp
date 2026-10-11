#include <bits/stdc++.h>

using namespace std;

constexpr int32_t x = ((1 << 29 ) - 1) << 1;

void solve(void);
int32_t answer(int32_t o, int32_t r);

bool tx = false;

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    solve();
  } 
  return 0;
}

void solve(void)
{
  cout << x << endl;
  int32_t o; cin >> o;
  if ( -1 == o )
    exit(-1);
  cout << 0 << ' ' << 1 << endl;
  int32_t r; cin >> r;
  if ( -1 == r )
    exit(-1);

  cout << answer(o, r) << endl;
}

int32_t answer(int32_t o, int32_t r)
{
  if ( ( o < x && (o == (x & r)) ) || ( (o & 1) ^ (r & 1) ) )
    return 0;
  else
    return 1;
}
