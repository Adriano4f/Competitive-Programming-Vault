#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  size_t N, M, K; cin >> N >> M >> K;

  size_t sum = 0;
  vector<size_t> A(N);
  vector<bool> eaten(N);
  for ( int64_t i = N-1; i >= 0; --i )
  {
    cin >> A[i];
    if ( A.size() - (size_t)i > M )
    {
      if ( eaten.back() )
        sum -= A.back();

      A.pop_back(), eaten.pop_back();
    }
    if ( sum + A[i] > K )
      cout << "No\n";
    else 
      cout << "Yes\n", sum += A[i], eaten[i] = true;;
  }
  return 0;
}

