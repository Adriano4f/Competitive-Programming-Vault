#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  size_t H, W; cin >> H >> W;
  pair<int64_t, int64_t> LT = {0, 0}, RB = {H-1, W-1};

  vector<string> G(H);
  for ( string & g : G )
    cin >> g;
  
  for ( size_t i = LT.first; i <= RB.first; ++i )
  {
    bool blank = true;
    for ( size_t j = LT.second; j <= RB.second; ++j )
    {
      
      if ( G[i][j] == '#' )
      {
        blank = false;
        break;
      }
    }
    if ( blank )
      ++LT.first;
    else
      break;
  }

  for ( int64_t i = RB.first; i >= LT.first; --i )
  {
    bool blank = true;
    for ( size_t j = LT.second; j <= RB.second; ++j )
    {
      if ( G[(size_t)i][j] == '#' )
      {
        blank = false;
        break;
      }
    }
    if ( blank )
      --RB.first;
    else
      break;
  }

  for ( size_t i = LT.second; i <= RB.second; ++i )
  {
    bool blank = true;
    for ( size_t j = LT.first; j <= RB.first; ++j )
    {
      if ( G[j][i] == '#' )
      {
        blank = false;
        break;
      }
    }
    if ( blank )
      ++LT.second;
    else
      break;
  }

  for ( int64_t i = RB.second; i >= LT.second; --i )
  {
    bool blank = true;
    for ( size_t j = LT.first; j <= RB.first; ++j )
    {
      if ( G[j][(size_t)i] == '#' )
      {
        blank = false;
        break;
      }
    }
    if ( blank )
      --RB.second;
    else
      break;
  }

  for ( size_t i = LT.first; i <= RB.first; ++i )
  {
    for ( size_t j = LT.second; j <= RB.second; ++j )
    {
      cout << G[i][j];
    }
    cout << '\n';
  }

  return 0;
}
