// PENDING
// Reason: does not compile — undeclared u, v in query call at line 22
// Next step: define u and v or finish the interactive tree strategy

#include <bits/stdc++.h>

using namespace std;

bool query(size_t u, size_t v, size_t d)
{
  cout << "? " << u << ' ' << v << ' ' << d << endl;
  bool ret; cin >> ret;
  return ret;
}
int main(void)
{
  int32_t tc; cin >> tc;

  while (tc--)
  {
    size_t N; cin >> N;

    size_t d = 0;
    for ( size_t i = 2; i <= N; ++i )
    {
      bool is = query(u, v, d+1);
      if ( is )
      {

      }
    }
  }
  return 0;
}
