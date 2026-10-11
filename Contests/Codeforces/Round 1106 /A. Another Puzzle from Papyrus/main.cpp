#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N; int32_t C; cin >> N >> C;
    vector<int32_t> A(N), B(N);
    for ( auto & a : A )
      cin >> a;
    for ( auto & b : B )
      cin >> b;



    int32_t ans = 0;
    bool add = false;
    for ( size_t i = 0; i < N; ++i )
    {
      int32_t tmp = A[i] - B[i];
      if ( tmp < 0 )
      {
        add = true;
        ans = 0;
        break;
      }
      ans += tmp;
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    if ( add )
      for ( size_t i = 0; i < N; ++i )
      {     
        int32_t tmp = A[i] - B[i];
        if ( tmp < 0 )
        {
          ans = -1 - add*C;
          break;
        }
        
        ans += tmp;
      }

    cout << ans + add*C << '\n';
  } 
  return 0;
}
