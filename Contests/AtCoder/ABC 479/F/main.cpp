#include <bits/stdc++.h>

using namespace std;

struct Node
{
  int64_t lazy;
};

struct SegTree
{
  vector<Node> T;
  
  size_t L = 0, R;
  SegTree(size_t _R) : L(0), R(_R-1) { T.resize(R*4); }
  
  void Build(const vector<pair<size_t, size_t>> &A, size_t v = 1, size_t tl = 0, size_t tr = SIZE_MAX)
  {
    if ( tr == SIZE_MAX )
      tr = R;


    if ( tl == tr )
    {
      T[v].lazy = (int64_t)A[tl].first;
            cout << tl << ' ' << A[tl].first << ' ' << T[v].lazy << ' ';
    }
    else
    {
      size_t tm = tl + (tr-tl)/2;

      Build(A, v*2, tl, tm);
      Build(A, v*2+1, tm+1, tr);
      T[v].lazy = 0;
    }
  }

  void Update(int64_t val, size_t l, size_t r, size_t v = 1, size_t tl = 0, size_t tr = SIZE_MAX)
  {
    if ( tr == SIZE_MAX )
      tr = R, l = min(l, r), r = max(l, r);
    
    if ( r < tl || tr < l )
      return;
    if ( l <= tl && tr <= r )
    {
      T[v].lazy += val;
      return;
    }

    size_t tm = tl + (tr-tl)/2;
    T[v*2].lazy += T[v].lazy;
    T[v*2+1].lazy += T[v].lazy;
    T[v].lazy = 0;
    Update(val, l, r, v*2, tl, tm);
    Update(val, l, r, v*2, tm+1, tr);
  }

  int64_t Query(size_t pos, size_t v = 1, size_t tl = 0, size_t tr = SIZE_MAX)
  {
    if ( tr == SIZE_MAX )
      tr = R;
    
    if ( tl == pos && pos == tr )
    {
      return T[v].lazy;
    }

    size_t tm = tl + (tr-tl)/2;
    T[v*2].lazy += T[v].lazy;
    T[v*2+1].lazy += T[v].lazy;
    T[v].lazy = 0;
    if ( pos <= tm )
      return Query(pos, v*2, tl, tm);
    else
      return Query(pos, v*2+1, tm+1, tr);
  }
  
};

int main(void)
{
  size_t N; cin >> N;
  vector<pair<size_t, size_t>> A(N);
  vector<size_t> F(N);
  for ( size_t i = 0; i < N; ++i )
      cin >> A[i].first, A[i].second = i;
  
  for ( size_t i = 0; i < N; ++i )
      cin >> F[i];

  sort(A.begin(), A.end());
  SegTree T(N);
  T.Build(A);

  size_t ans = 0;

  for ( size_t i = 0; i < N; ++i )
  {
    const size_t pos = A[i].first + Query(i);
    const size_t idx = A[i].second;

    if ( pos == F[idx] )
    auto it = upper_bound(A[i].first, A[i].second, {pos, 0});
    if ( F[idx] < pos )
    {
      
    }
  }
  return 0;
}
