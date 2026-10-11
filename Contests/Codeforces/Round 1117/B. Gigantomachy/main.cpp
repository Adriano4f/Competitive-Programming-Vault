#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N, M; cin >> N >> M;
    vector<int32_t> A(N), B(M);
    for ( auto & a : A )
      cin >> a;
    for ( auto & b : B )
      cin >> b;
    
    int64_t sumA = A.back();
    for ( size_t i = 0; i < N-1; ++i )
      sumA += A[i] - A[i+1] + 1;

    int64_t sumB = B.back();
    for ( size_t i = 0; i < M-1; ++i )
      sumB += B[i] - B[i+1] + 1;

    if ( sumA >= sumB )
      cout << 1 << '\n';
    else 
      cout << 2 << '\n';

  } 
  return 0;
}
