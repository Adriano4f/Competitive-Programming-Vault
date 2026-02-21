//UNFINISHED

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  size_t N, Q; cin >> N >> Q;
  vector<int> S(N+1);

  char last;
  {char s; cin >> s; last = s;}
  S[1] = 1;
  
  for ( size_t i = 1; i < N; ++ i )
  {
    S[i+1] = S[i];
    char s; cin >> s;
    
    if ( last == s )
      ++S[i+1];

    last = s;
    cout << " " << s << " " << S[i+1] << " :\n";
  }
  
  for ( size_t i = 0; i < Q; ++i )
  {
    size_t l, r; cin >> l >> r;
    cout << S[r] - S[l-1] << '\n';
  }
  return 0;
}