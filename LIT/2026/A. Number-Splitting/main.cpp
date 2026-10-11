#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  size_t N; cin >> N;
  size_t ans = 0;
  vector<string> A(N);

  for ( string &a : A )
    cin >> a;
  
  for ( const string &S : A )
  {
    for ( const char &s : S )
    {
      int16_t digit = int16_t(s - '0');
      if ( !digit )
        continue;

      ans += digit - 1;
      ++ans;
    }
    --ans;
  }
  cout << ans << '\n';
  return 0;
}
