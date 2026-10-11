#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  size_t N, K; cin >> N >> K;
  vector<size_t> A;
  for ( size_t i = 0; i < N; ++i )
  {
    
    size_t input; cin >> input;
    if ( i )
      input += A.back();

    A.emplace_back(input % K);
  }
  
  unordered_map<size_t, size_t> memo;
  
  memo[A[0]] = ( 0 == A[0] ? 1 : 0 );
  for ( size_t i = 1; i < N; ++i )
    memo[A[i]] = ( memo.count(A[i]) || A[i] == 0 ? max(memo[A[i-1]], memo[A[i]] + 1) : memo[A[i-1]] );

  cout << memo[A.back()];
  return 0;
}
