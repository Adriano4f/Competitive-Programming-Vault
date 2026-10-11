#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point
{
  int32_t x, y, i;

  bool operator<(const point& b) const 
  {
    if ( x == b.x )
    {
      return y < b.y;
    }
    
    return x < b.x;
  }
};

int main(void)
{
  size_t N; cin >> N;
  vector < point > P(N);

  for ( size_t i = 0; i < N; ++i )
  {
    cin >> P[i].x >> P[i].y;
    P[i].i = (int32_t)i+1; 

  }

  sort(P.begin(), P.end());
  point ref = P[0];

  int32_t count = 0;
  for ( const point& p : P )
  {
    if ( p.y <= ref.y )
    {
      ++count;
      ref.y = p.y;
    }
  }

  cout << count;
  return 0;
}
