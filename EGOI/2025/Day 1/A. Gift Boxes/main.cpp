#include <bits/stdc++.h>

using namespace std;

#define i32 int32_t
#define u32 uint32_t


uint32_t T, N;

void get_ix(i32 &prefix, i32 &suffix, const vector<u32> &A);
pair<u32, u32> ans(const i32 prefix, const i32 suffix, const vector<u32> &A);

int32_t main(void)
{
  cin >> T >> N;

  vector<u32> A(N);
  for ( u32 &a : A )
    cin >> a;
  
  int32_t prefix = -1, suffix = (i32)N;
  get_ix(prefix, suffix, A);
  pair<u32, u32> res = ans(prefix, suffix, A);
  cout << res.first << ' ' << res.second;
}

// other fns
void get_ix(i32 &prefix, i32 &suffix, const vector<u32> &A)
{
  set<u32> s;
  for ( uint32_t i = 0; i < N; ++i )
  {
    if ( s.count( A[i] ) )
      break;

    prefix = (i32)i;
    s.insert( A[i] );
  }

  s = set<u32>();
  for ( uint32_t i = N-1; i < N; --i )
  {
    if ( s.count( A[i] ) )
      break;

    suffix = (i32)i;
    s.insert( A[i] );
  }

  return;
}

pair<u32, u32> ans(i32 prefix, i32 suffix, const vector<u32> &A)
{
  uint32_t l = (u32)(prefix+1), r = (u32)(suffix-1);
  vector<i32> idx(T, -1);
  for ( int32_t i = (i32)N-1; i >= suffix; --i )
    idx[A[(u32)i]] = i;

  for ( int32_t i = prefix; i >= 0; --i )
  {
    int32_t id = idx[A[(u32)i]];
    if ( -1 == id || id == i)
      continue;

    uint32_t len1 = (u32)(id - suffix),
    len2 = (u32)(prefix-i);

    if ( len1 >=  len2 )
    {
      l = (u32)(i);
      prefix = i-1;
    }
    else
    {
      r = max(r, (u32)(id));
      suffix = id+1;
    }
  }
  return {l, r};
}
