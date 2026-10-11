#include <bits/stdc++.h>

using namespace std;

size_t H, W, K;
vector<string> G;
vector< vector<size_t> > dis;
vector< bool > Gh, Gw;

int64_t movesi[] = { -1, 0, 1, 0};
int64_t movesj[] = { 0, -1, 0, 1};

bool isValid( int64_t i, int64_t j )
{
  return (0 <= i ) && ( i < (int64_t)H ) && ( 0 <= j ) && ( j < (int64_t)W );
}

struct cell
{
  int64_t i, j, d;

  bool operator< ( const cell & o ) const
  {
    return d > o.d;
  }
};


size_t bfs( priority_queue< cell > & pq )
{
  size_t to_ret = 0;
  

  while ( !pq.empty() )
  {
    
    cell u = pq.top();
    pq.pop();
    if ( u.d > K || dis[u.i][u.j] <= u.d )
      continue;

    ++to_ret;

    dis[u.i][u.j] = u.d;
    for ( size_t k = 0; k < 4; ++k )
    {
      int64_t x = u.i + movesi[k], y = u.j + movesj[k];

      if ( !isValid(x, y) || G[x][y] == '#' )
        continue;
      
      pq.push( (cell){x, y, u.d+1 } );
    }
  }

  return to_ret;
}

int main(void)
{
  cin >> H >> W >> K;

  Gh.resize(H, true), Gw.resize(W, true);
  G.resize(H), dis.resize(H, vector<size_t>(W, SIZE_MAX));
  for ( size_t i = 0; i < H; ++i )
  {
    cin >> G[i];
    for ( size_t j = 0; j < W; ++j )
      if ( G[i][j] == '#' )
        Gh[i] = false, Gw[j] = false;
  }

  priority_queue<cell> pq;
  for ( size_t i = 0; i < H; ++i )
  {
    for ( size_t j = 0; j < W; ++j )
    {
      if ( Gh[i] && Gw[j] )
      {
        pq.push( (cell){int64_t(i), int64_t(j), 0} );
      }
    }
  }

  cout << bfs(pq) << '\n';
  return 0;
}
