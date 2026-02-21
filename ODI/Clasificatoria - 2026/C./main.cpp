//UNFINISHED

#include <bits/stdc++.h>

using namespace std;


int64_t po(int64_t n, int32_t e);

int64_t f(int32_t n);

int64_t next_n(int32_t n, int64_t x);

int64_t calc(int64_t l, int64_t r, int32_t n);

int64_t brute_force(int64_t l, int64_t r);

int64_t compute(int64_t l, int64_t r);

//MAIN
int32_t main(void)
{
  size_t Q; cin >> Q;

  while ( Q-- )
  {
    int64_t l, r; cin >> l >> r;
    cout << compute(l, r) << '\n';
  }
  return 0;
}

//OTHER

int64_t po(int64_t n, int32_t e)
{
  if ( e == 0 )
    return 1;

  return n*po(n, e-1);
}

int64_t f(int32_t n)
{
  if ( n == 2 )
    return 2;
  
  return n*f(n-1);
}

int64_t C(int32_t N, int32_t K)
{
  return f(N)/f(K)/f(N-K);
}

int64_t next_n(int32_t n, int64_t x)
{
  int64_t sum = 0;
  for ( int i = 0; i <= n; ++i )
  {
    sum += C(n, i)*po(x,n-i);
  }
  return sum;
}

int64_t calc(int64_t l, int64_t r, int32_t n)
{
  int64_t sum = 0, 
  x = po(7,n);

  while ( x < l )
  {
    next_n(n, x);
  }
  
  while ( x < r )
  {
    ++sum;
    next_n(n, x);
  }

  return sum;
}

int64_t compute(int64_t l, int64_t r)
{
  int64_t sum = r - l + 1;

  sum -= brute_force(l, r);

  for ( int n = 0; n < 9; ++n )
  {
    sum -= calc(l, r, n);
  }

  return sum;
}

int64_t brute_force(int64_t l, int64_t r)
{
  int64_t sum = 0;
  for ( int i = 1; i < 7; ++i )
  {
    for ( int j = 1; j < 60; ++j )
    {
      int64_t n = po(i, j);
      if ( l <= n && n <= r )
        ++sum;
      
      if ( r < n )
        break;
    }
  }

  return sum;
}

