#include <bits/stdc++.h>

using namespace std;

void add(int32_t v, int32_t L, int32_t R, vector<int32_t> &V);

int main(void)
{
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N; cin >> N;
    
    map<int32_t, int32_t> id;
    vector<uint32_t> A(N), B(N), C;
    vector<int32_t> shift(N);

    for ( uint32_t & a : A )
      cin >> a,  
      C.emplace_back(a);

    for ( uint32_t & b: B )
      cin >> b;
    
    sort(C.begin(), C.end());
    bool pos = true;
    for ( size_t i = 0; i < N; ++i ) 
    {
      if ( C[i] > B[i] )
      {
        pos = false;
        break;
      }
      for ( size_t j = 0; j < N; ++j )
      {
        if ( A[j] != C[i] )
          continue;
        A[j] = i;
        id[i] = j;
        break;
      }
    }
    if ( !pos )
    {
      cout << -1 << '\n';
      continue;
    }
    
    int64_t ans = 0;
    for ( int32_t i = 0; i < N; ++i )
    {
      ans += abs(id[i] + shift[id[i]] - i);
      
      if ( id[i] + shift[id[i]] < i )
        add(1, id[i] , i, shift);

      else if ( id[i] + shift[id[i]] > i )
        add(-1, i, id[i], shift); 
    }
    
    cout << ans << '\n';
  }
  return 0;
}

void add(int32_t v, int32_t L, int32_t R, vector<int32_t> &V)
{
  for ( size_t i = (size_t)L; i <= (size_t)R && i < V.size(); ++i )
  {
    V[i] += v;
  }

  return;
}
