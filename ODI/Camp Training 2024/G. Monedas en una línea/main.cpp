//UNFINISHED
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
    double tmp = 0;
    for (size_t i = 0; i < N-1; ++i )
    {
      if ( i < N-2 && dist(C[i], C[i+2]) > dist(C[i], C[i+1]) + dist(C[i+1], C[i+2]))
      {
        tmp += dist(C[i], C[i+2]);
        ++i;
      }
      else
        tmp += dist(C[i], C[i+1]);
    }

    sum = min(sum, tmp);
  } while ( next_permutation( C.begin(), C.end() ) );

  cout << fixed << setprecision(15) << sum << '\n';
  return 0;
}

double dist(int32_t r1, int32_t r2)
{
  return 2*sqrt((int64_t)r1 * r2);
}
