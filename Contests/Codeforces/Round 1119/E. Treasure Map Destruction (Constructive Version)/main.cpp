#include <bits/stdc++.h>

using namespace std;

struct Node
{
  bool unav, has;

  Node operator| ( Node b ) const
  {
    return (Node){unav | b.unav, has | b.has};
  }

  Node operator& ( Node b ) const
  {
    return (Node){unav & b.unav, has & b.has};
  }
};

struct Tree
{
  vector<Node> T;
  vector<bool> marked;

  Tree( size_t N ) 
  {
    T.resize(4*N);
    marked.resize(4*N);
  }

  void push( size_t v )
  {
    if ( !marked[v] )
      return;
    
    T[v*2] = T[v*2+1] = T[v];
    marked[v*2] = marked[v*2+1] = true;
    marked[v] = false;
  }

  void update( size_t ql, size_t qr, Node new_val, size_t v = 1, size_t l = 0, size_t r = INT_MAX )
  {
    if ( INT_MAX == r )
      r = T.size()/4 - 1;
    
    if (ql > qr)
      return;
    if ( r < ql || qr < l )
      return;

    if ( ql <= l && r <= qr )
    {
      T[v] = T[v] | new_val;
      marked[v] = true;
      return;
    }


    push(v);
    size_t mid = l + (r-l)/2;
    update(ql, qr, new_val, v*2, l, mid);
    update(ql, qr, new_val, v*2+1, mid+1, r);
  }

  Node get(size_t pos, size_t v = 1, size_t l = 0, size_t r = INT_MAX)
  {
    if ( INT_MAX == r )
      r = T.size()/4 - 1;

    if ( r < pos || pos < l )
      return (Node){0, 0};

    if ( l == pos && pos == r )
    {
      return T[v];
    }

    push(v);
    size_t mid = l + (r-l)/2;
    return get(pos, v*2, l, mid) | get(pos, v*2+1, mid+1, r);
  }
};

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N; cin >> N;
    vector<int64_t> A(N);
    for ( auto & a : A )
      cin >> a;

    Node unav = {1, 0};
    Node has = {0, 1};

    Tree T(N);

    for ( size_t i = 0; i < N; ++i )
    {
      if ( -1 == A[i] )
        continue;

      if ( A[i] <= i )
        T.update(i - A[i], i - A[i], has);
      if ( A[i] < N-i )
        T.update(i + A[i], i + A[i], has);

      if ( 0 != A[i] )
        T.update(max( int64_t(0), int64_t(i) - A[i] + 1), 
                     min( N-1, i + A[i] - 1 ), 
                      unav);
    }
    
    vector<bool> ans(N);
    bool pos = true;
    for ( size_t i = 0; i < N; ++i )
    {
      Node buf = T.get(i);
      ans[i] = (ans[i] || buf.has || !buf.unav) && !buf.unav;

      if ( -1 == A[i] )
        continue;
      Node tmp1 = (Node){1, 0}, tmp2 = (Node){1, 0};
      if ( A[i] <= i )
        tmp1 = T.get(i - A[i]), ans[i - A[i]] = ( tmp1.has || !tmp1.unav) && !tmp1.unav;
      if ( A[i] < N-i )
        tmp2 = T.get(i + A[i]), ans[i + A[i]] = ( tmp2.has || !tmp2.unav) && !tmp2.unav;

      Node tmp3 = tmp1 & tmp2;

      if ( tmp3.unav )
        pos = false;
    }
    
    if ( pos )
    {
      for ( bool a : ans )
        cout << a;
    }
    else
      cout << -1;

    cout << '\n';
  }

  return 0;
}

