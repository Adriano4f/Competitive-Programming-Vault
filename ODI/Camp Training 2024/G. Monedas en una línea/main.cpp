#include <bits/stdc++.h>

using namespace std;

double dist(int32_t r1, int32_t r2);

int main(void)
{
  size_t N; cin >> N;
  
  vector<int32_t> C(N);
  for ( int32_t &c : C )
    cin >> c;
  
  sort( C.begin(), C.end() );

  double sum = (double)INT64_MAX;
  do
  {
    vector<double> tmp(N);
    for (size_t i = 0; i < N; ++i )
    {
      double pos = 0;

      for ( size_t j = 0; j < i; ++j )
        pos = max(pos, tmp[j] + dist(C[i], C[j]) );

      tmp[i] = pos;
    }

    sum = min(sum, tmp[N-1]);
  } while ( next_permutation( C.begin(), C.end() ) );

  cout << fixed << setprecision(15) << sum << '\n';
  return 0;
}

double dist(int32_t r1, int32_t r2)
{
  return 2*sqrt((int64_t)r1 * r2);
}
