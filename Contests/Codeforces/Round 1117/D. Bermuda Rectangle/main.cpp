#include <bits/stdc++.h>

using namespace std;

size_t S, Q;

void compute_divisors( vector<size_t> & d)
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
  auto it = lower_bound(d.begin(), d.end(), x);
  
  if ( it == d.end() )
    return pref.back();
   
  size_t i = size_t(it - d.begin());
  size_t h = S/d[i];
  
  if ( i == 0 )
    return x * h;
  else
    return pref[i-1] + h * ( x - d[i-1] );
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    cin >> S >> Q;
    vector<size_t> d, pref;
    compute_divisors(d);
    
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
      
      auto it = upper_bound(d.begin(), d.end(), S/y);
      size_t z = min(x, *(--it));

      cout << z*y + area(x, d, pref) - area(z, d, pref) << '\n';
    }
  } 
  return 0;
}
