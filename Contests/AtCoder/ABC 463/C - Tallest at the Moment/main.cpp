#include <bits/stdc++.h>

using namespace std;

struct query
{
  uint32_t t, i;

  bool operator<(const query& b) const 
  {
    if ( t == b.t )
    {
      return i < b.i;
    }
    
    return t < b.t;
  }
  bool operator>(const query& b) const 
  {
    if ( t == b.t )
    {
      return i > b.i;
    }
    
    return t > b.t;
  }
};

struct takahashi
{
  uint32_t h, t;

  bool operator<(const takahashi& b) const 
  {
    if ( t == b.t )
    {
      return h < b.h;
    }
    
    return t < b.t;
  }
};

int main(void)
{
  size_t N; cin >> N;
  vector< takahashi > A(N);
  for ( takahashi & a : A )
    cin >> a.h >> a.t;
  
  size_t Q; cin >> Q;
  vector< query > T(Q);
  vector<uint32_t> ans(Q);
  Q = 0;
  for ( query & t : T )
    cin >> t.t, t.i = (uint32_t)Q++;
  
  sort(A.begin(), A.end());
  sort(T.begin(), T.end(), greater<query>());

  priority_queue<uint32_t> pq;
  int64_t j = (int64_t)N-1;
  for ( size_t i = 0; i < Q; ++i )
  {
    if ( j >= 0 && T[i].t < A[(size_t)j].t )
    {
      for (; j >= 0 && T[i].t < A[(size_t)j].t; --j )
        pq.push(A[(size_t)j].h);
    }

    ans[T[i].i] = pq.top();
  }
  
  for ( size_t i = 0; i < Q; ++i )
  {
    cout << ans[i] << '\n';
  }
  return 0;
}
