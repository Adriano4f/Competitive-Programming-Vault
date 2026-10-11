// PENDING
// Reason: does not compile — empty if condition at line 39
// Next step: complete the rectangle/circle containment check

#include <bits/stdc++.h>

using namespace std;

struct point
{
  size_t x, y;
  bool operator< ( const point & other) const
  {
    return make_pair(x, y) < make_pair(other.x, other.y);
  }
};

point corner1( point P1, point P2 )
{
  return { max(P1.x, P2.x), max(P1.y, P2.y) };
}
point corner2( point P1, point P2 )
{
  return { min(P1.x, P2.x), min(P1.y, P2.y) };
}


int main(void)
{
  int32_t tc; cin >> tc;

  while (tc--)
  {
    point P, Q, R, S; cin >> P.x >> P.y >> Q.x >> Q.y >> R.x >> R.y >> S.x >> S.y;
    map<point, bool> f;
    f[corner1(P, Q)] = f[corner2(P, Q)] = true;

    if ( P.x == Q.x )
      f[{P.x, (P.y + Q.y)/2}] = true;
    else if ( P.y == Q.y )
      f[{(P.x + Q.x)/2, P.y}] = true;

    if ()
      cout << "Yes\n";
    else
      cout << "No\n";
  }

  return 0;
}
