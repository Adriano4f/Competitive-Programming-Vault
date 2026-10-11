#include <bits/stdc++.h>

using namespace std;

struct vowel
{
  int32_t v[5];

  vowel operator+=(vowel& other)
  {
    for ( size_t i = 0; i < 5; ++i )
    {
      v[i] += other.v[i];
    }
    return *this;
  }
  int32_t operator-(vowel& other)
  {
    int32_t ans = INT_MAX;
    for ( size_t i = 0; i < 5; ++i )
    {
      ans = min(ans, v[i] - other.v[i]);
    }
    return ans + 1;
  }
};

int main(void)
{
  size_t N; cin >> N;
  string s; cin >> s;

  map<char, size_t> m;
  m['a'] = 0, m['e'] = 1, m['i'] = 2, m['o'] = 3, m['u'] = 4;

  vector<vowel> V(N+1);
  for (size_t i = 1; i <= N; ++i )
  {
    ++V[i].v[m[s[i-1]]];
    V[i] += V[i-1];
  }

  int32_t Q; cin >> Q;
  while(Q--)
  {
     size_t l, r; cin >> l >> r;
     cout << V[r] - V[l-1] << '\n';
  }
  return 0;
}
