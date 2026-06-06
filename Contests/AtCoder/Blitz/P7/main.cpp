#include <bits/stdc++.h>

using namespace std;

int32_t N;
vector < bool > A;

int32_t main(void)
{
  cin >> N;
  A.resize(N, false);
  for ( int i = 0; i < N; ++i )
  {
    int16_t in; cin >> in;
    A[i] = (bool)in;
  }

  uint64_t i = 0, flip = 0;
  bool pos = true;
  while ( i < A.size() )
  {
    while ( i < A.size() && (flip%2? !A.back() : A.back()) == false )
      A.pop_back();
    

    bool a = A[i];
    if ( flip%2 )
      a = !a;

    
    if ( a )
    {
      pos = false;
      break;
    }
      
    ++i; ++flip;
  }

  if ( pos )
    cout << "Yes";
  else
   cout << "No";
}
