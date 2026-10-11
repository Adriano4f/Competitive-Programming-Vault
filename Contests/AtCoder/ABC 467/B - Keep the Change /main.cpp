#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  size_t N; cin >> N;

  int64_t X = 0, Y = 0;
  for ( size_t i = 0; i < N; ++i )
  {
    int64_t A, B; cin >> A >> B;
    string S; cin >> S;

    if ( "keep" == S )
      X += B;
    else  
      X += A;

    Y += A;
  }

  cout << X - Y << '\n';
  return 0;
}
