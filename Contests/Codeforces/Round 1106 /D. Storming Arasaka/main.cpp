#include <bits/stdc++.h>

using namespace std;

vector<uint32_t> Leonhard_Euler(uint32_t N);
uint32_t gcd(uint32_t a, uint32_t b);

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    uint32_t N; cin >> N;
    vector<uint32_t> divisors = Leonhard_Euler(N);
    size_t L = 1, L2 = 0; size_t ans = 1;
    for ( size_t i = 1; i < divisors.size(); ++i )
    {
      bool cont = false;
      for ( int64_t j = (int64_t)i-1; j >= L2; --j )
      {
        if ( !(divisors[(size_t)j] % divisors[i]) )
        { 
          cont = true;
          break;
        }
      }
      if ( cont || 1 == gcd(divisors[L-1], divisors[i]) )
      {
        if ( i == divisors.size() - 1 )
          L2 = L, ++L, i = L, ++ans;

        continue;
      }
      
      swap(divisors[L], divisors[i]);
      ++L;
    }

    cout << ans << '\n';
  } 
  return 0;
}

vector<uint32_t> Leonhard_Euler(uint32_t N)
{
  vector<uint32_t> divisors = {(uint32_t)N};
  for ( size_t i = (size_t)sqrt(N); i > 1; --i )
  {
    if ( N % i )
    {
      divisors.emplace_back(i);
      
      if ( i != N/i )
        divisors.emplace_back(i);
    }
  
  }
  sort(divisors.begin(), divisors.end(), greater<uint32_t>());
  return divisors;
}

uint32_t gcd(uint32_t a, uint32_t b)
{
  a = max(a,b);
  return ( 0 == b ? gcd(b, a % b) : a );
}
