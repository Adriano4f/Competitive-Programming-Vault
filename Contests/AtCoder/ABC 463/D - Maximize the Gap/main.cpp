// PENDING
// Reason: skeleton / reads input but produces no output or result
// Next step: implement the solution and add the required output

#include <bits/stdc++.h>

using namespace std;

struct cloth
{
  int32_t l, r;

  bool operator<(const cloth& b) const 
  {
    return ( l == b.l ? r > b.r : l > b.l );
  }
  
  bool operator>(const cloth & b) const
  {
    return ( l == b.l ? r > b.r : l > b.l );
  }
};


size_t N, K;
vector < cloth > P;


int main(void)
{
  cin >> N >> K;
  P.resize(N);
  for ( cloth & p : P )
    cin >> p.l >> p.r;

  sort(P.begin(), P.end());

  return 0;
}

