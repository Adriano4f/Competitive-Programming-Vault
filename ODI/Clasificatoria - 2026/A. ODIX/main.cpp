#include <bits/stdc++.h>

using namespace std;

struct C
{
  int32_t n = 0, m = 0, k = 0;

  C operator-(const C &other)
  {
    return (C){ n - other.n, m - other.m, k - other.k };
  }

  bool operator==(const C &other) const
  {
    return ( (n == other.n) && (m == other.m) && (k == other.k) );
  }

  bool operator>(const C &other) const
  {
    return ( (n > other.n) || (m > other.m) || (k > other.k) );
  }
};

void 
Input(vector<C> &S);

int32_t 
main(void)
{
  size_t L; cin >> L;
  vector<C> S(L+1);
  Input(S);

 
  int32_t N, M, K; cin >> N >> M >> K;
  C goal = (C){N, M, K};

  int32_t maxlen = -1;
 
  for ( size_t i = 0, j = 1; i < L && j <= L; ++j )
  {
    C _new = (S[j] - S[i]);
    if (  _new == goal )
      maxlen = max(maxlen, (int)(j - i));
    else if ( _new > goal )
    {
      ++i, --j;
      continue;
    }
  }

  cout << maxlen;
  return 0;
}

void 
Input(vector<C> &S)
{
  for ( size_t i = 0; i < S.size()-1; ++i )
  {
    S[i+1] = S[i];
    char s; cin >> s;
    switch (s)
    {
      case 'O':
      ++S[i+1].n;
      break;

      case 'D':
      ++S[i+1].m;
      break;

      case 'I':
      ++S[i+1].k;
      break;
    }
  }
}
