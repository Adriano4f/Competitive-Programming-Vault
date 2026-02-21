// THIS WORKS FOR A HALF OF THE SCORE

#include <bits/stdc++.h> 

using namespace std; 

struct package 
{ 
  int64_t w = 0, v = 0; 
}; 

int64_t W; 
size_t N; 
vector<package> P; 
vector< unordered_map<int64_t, int64_t> > memo; 

int64_t dp(size_t i, int64_t w) 
{ 
  if ( w <= 0 || i >= N ) 
  return 0; 

  if ( memo[i].count(w) ) 
  { 
    return memo[i][w]; 
  }

  package cur = P[i]; 
  memo[i][w] = max( 
    (w - cur.w >= 0? dp(i+1, w-cur.w) + cur.v : 0), 
    dp(i+1, w) 
  ); 
  
  return memo[i][w];
} 

int32_t main(void) 
{ 
  cin >> W >> N; P.resize(N); 
  memo.resize(N);

  for ( package &p : P ) 
  { 
    cin >> p.w >> p.v; 
  }
  cout << dp(0, W); 
  return 0;
}