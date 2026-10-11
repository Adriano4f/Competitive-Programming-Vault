// PENDING
// Reason: skeleton / reads input but produces no output or result
// Next step: implement the solution and add the required output

#include <bits/stdc++.h>

using namespace std;

void compute_divisors( size_t S, vector<size_t> & d)
{
  for ( size_t i = 1; i * i <= S; ++i )
  {
    if ( 0 == S % i )
    {
      d.emplace_back(i);
      if ( i * i != S )
        d.emplace_back(S/i);
    }
  }
  sort(d.begin(), d.end());
  return;
}

size_t area(size_t x, vector<size_t> & d, vector<size_t> & pref )
{
  auto it = upper_bound(d.begin(), d.end(), x);
  
  if ( it != d.begin() )
    --it;

}

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t S, Q; cin >> S >> Q;
    vector<size_t> d, pref;
    compute_divisors(S, d);
    
    for ( size_t i = 0; i < d.size(); ++i )
    {
      size_t last = ( i == 0 ? 0 : d[i-1] ),
      h = S/d[i];
      pref.emplace_back( h * (d[i] - last)  );

      if ( i )
        pref[i] += pref[i-1];
    }

    
    for ( size_t i = 0; i < Q; ++i )
    {
      size_t x, y; cin >> x >> y;
      
    }
  } 
  return 0;
}
