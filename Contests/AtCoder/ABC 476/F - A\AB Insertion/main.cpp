#include <bits/stdc++.h>

using namespace std;

struct node
{
  int64_t r, m;

  void join(const node & a, const node & b )
  {
    r = a.r + b.r;
    m = min(a.m, a.r + b.m);
  }
};

struct tree
{
  vector<node> T;
  tree( size_t N ) 
  {
    T.resize(N*4);
  }
  void build(const string &S, size_t v = 1, size_t l = 0, size_t r = INT64_MAX)
  {
    if ( INT64_MAX == r )
      r = T.size()/4;

    if ( l == r )
    {
      T[v].r = T[v].m = ( S[l] == 'A' ? 1 : -1 );
      return;
    }
    
    size_t mid = l + ( r - l ) / 2;
    build(S, v*2, l, max(l, mid));
    build(S, v*2 + 1, min(mid+1, r), r);

    T[v].join(T[v*2], T[v*2+1]);
  }

  void update(const size_t pos, const char val, size_t v = 1, size_t l = 0, size_t r = INT64_MAX)
  {
    if ( INT64_MAX == r )
      r = T.size()/4;

    if ( r < pos || pos < l )
      return;
    
    if ( l == r && pos == l )
    {
      T[v].r = T[v].m = ( val == 'A' ? 1 : -1 );
      return;
    }
    
    size_t mid = l + ( r - l ) / 2;
    update(pos, val, v*2, l, max(l, mid));
    update(pos, val, v*2 + 1, min(mid+1, r), r);

    T[v].join(T[v*2], T[v*2+1]);
  }

  node query(size_t ql, size_t qr, size_t v = 1, size_t l = 0, size_t r = INT64_MAX )
  {
    if ( INT64_MAX == r )
      r = T.size()/4;

    if ( r < ql || qr < l )
      return node{0, INT_MAX};

    if ( ql <= l && r <= qr )
      return T[v];
    
    size_t mid = l + ( r - l ) / 2;
    node to_ret;
    to_ret.join(
      query(ql, qr, v*2, l, max(l, mid)), 
      query(ql, qr, v*2 + 1, min(mid+1, r), r)
    );
    return to_ret;
  }
};

int main(void)
{
  size_t N; cin >> N;
  string S; cin >> S;
  tree T(N);
  T.build(S);
  
  size_t Q; cin >> Q;
  for ( size_t q = 0; q < Q; ++q )
  {
    size_t op; cin >> op;
    switch (op)
    {
      case 1: 
        size_t i; char c; cin >> i >> c, --i;
        T.update(i, c);
        break;
      case 2:
        size_t l, r; cin >> l >> r, --l, --r;
        cout << ( T.query(l, r).m >= 0 ? "Yes\n" : "No\n" );
        break;
    }
  }
  return 0;
}
