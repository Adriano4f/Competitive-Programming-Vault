#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  size_t H, W; cin >> H >> W;
  cout << ( W*10000/H/H >= 25 ? "Yes\n" : "No\n" );
  return 0;
}
