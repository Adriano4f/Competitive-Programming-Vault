// __int128_t only works in GNU compilers that support so

#include <bits/stdc++.h>

using namespace std;

constexpr uint64_t MAXN = 1'000'000'000'000'000'100;

vector<uint64_t> Pos;
vector<int8_t> P;

//fn def
__int128_t 
po(uint64_t n, uint8_t e);

void 
precompute(void);

uint64_t 
sqrt_dif(uint64_t l, uint64_t r);

uint64_t 
sqrt_floor(uint64_t x) {
    uint64_t sq = (uint64_t)sqrtl(x);
    while ((sq + 1) * (sq + 1) <= x) 
      ++sq;

    while (sq * sq > x) 
      --sq;
    return sq;
}

uint64_t 
sqrt_ceil(uint64_t x) {
    uint64_t sq = sqrt_floor(x);
    if (sq * sq < x) ++sq;
    return sq;
}

//MAIN
int main(void)
{
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  precompute();

  uint32_t Q; cin >> Q;
  while ( Q-- )
  {
    uint64_t l, r; cin >> l >> r;
    auto it1 = lower_bound(Pos.begin(), Pos.end(), l);
    auto it2 = upper_bound(Pos.begin(), Pos.end(), r);

    cout << (r - l + 1) - (uint64_t)distance(it1, it2) - sqrt_dif(l, r) << '\n';
  }
  return 0;
}

// Other Fns
__int128_t 
po(uint64_t n, uint8_t e)
{
  __int128_t to_ret = 1;

  for (uint8_t i = 0; i < e; ++i)
  {
      to_ret *= n;
  }
  return to_ret;
}

void 
precompute(void)
{
  unordered_set<uint64_t> s;
  for ( uint8_t i = 3; i < 60; ++i )
  {
    uint64_t j = 2;
    __int128_t paw = po(j, i);
    uint64_t sq = (uint64_t)sqrt( (uint64_t)paw );
    while ( paw < MAXN )
    {
      if ( !s.count( (uint64_t) paw) &&  sq*sq != paw)
      {
        s.insert( (uint64_t) paw);
        Pos.emplace_back( (uint64_t) paw);
      }
      
      paw = po(++j, i);
      sq = sqrt_floor( (uint64_t) paw );
    }
  }

  sort(Pos.begin(), Pos.end());
}

uint64_t 
sqrt_dif(uint64_t l, uint64_t r)
{
  uint64_t s1 = sqrt_ceil(l);
  uint64_t s2 = sqrt_floor(r);
  if ( s2 >= s1 )
    return uint64_t(s2 - s1 + 1);
  
  return 0;
}
