#include <bits/stdc++.h>

using namespace std;


int main(void)
{
  ios_base::sync_with_stdio(false);

  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N, K; cin >> N >> K;
    vector <int32_t> A(N);
    
    for ( int32_t &a : A )
      cin >> a;
   
    sort( A.begin(), A.end(), greater<int32_t>());

    vector <int32_t> R(1), V(1);
    int32_t ref = V[0] = A[0]; size_t count = 0;
    for ( size_t i = 0; i < N; ++i )
    {
      if ( A[i] == ref )
      {
        ++R[count];
        continue;
      }
      
      ref = A[i];
      ++count;
      R.emplace_back(1);
      V.emplace_back(A[i]);
    }

    bool pos = false;
    for ( size_t i = 0; i < R.size(); ++i )
    {
      if ( R[i]%2  )
      {
        if ( i < R.size() - 1 && (size_t)(V[i] - V[i+1]) <= K )
          pos = true;
        else 
        continue;
      }
      else 
        pos = true;
    }
  
    cout << ( pos ? "YES\n" : "NO\n" );
  }
  return 0;
}

