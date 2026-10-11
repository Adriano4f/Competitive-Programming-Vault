#include <bits/stdc++.h>

using namespace std;

size_t gcd(size_t a, size_t b)
{
  if ( b == 0 )
    return a;
  
  a = a % b;

  if ( a < b )
    swap(a, b);

  return gcd(a, b);
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N; cin >> N;
    vector<size_t> A(N);
    for ( size_t & a : A )
      cin >> a;

    cout << gcd(A[0], A.back()) << '\n';
  }
  return 0;
}
