#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  size_t N; cin >> N;
  vector< vector<int32_t> > gift(N);
  for ( size_t i = 1; i <= N; ++i )
  {
    size_t K; cin >> K;
    for ( size_t j = 0; j < K; ++j )
    {
      size_t in; cin >> in;
      gift[in-1].emplace_back((int32_t)i);
    }
  }

  for ( size_t i = 0; i < N; ++i )
  {
    cout << gift[i].size() << ' ';
    for ( size_t j = 0; j < gift[i].size(); ++j )
    {
      cout << gift[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
