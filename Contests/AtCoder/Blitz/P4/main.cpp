#include <bits/stdc++.h>

using namespace std;

vector< vector < vector < char > > > blanket = { {{'#'}} };

vector < vector < char > > ans;

int32_t po(int8_t N)
{
  int32_t ret = 1;
  for ( int i = 0; i < N; ++i )
    ret *= 3;
  
  return ret;
}
void paste(int8_t N)
{

}

void compute_ans(int8_t N)
{
  if ( blanket[N-1].empty() && N-1 > 0 )
    compute_ans(N-1);
  
  for (int i = 0; i < N; ++i )
  {
  
  }
}

int32_t main(void)
{
 int8_t N; cin >> N;


 compute_ans(N);
 for ( vector<char> an : ans )
 {
  for ( char a : an )
    cout << a;
  
  cout << '\n';
 }
}
