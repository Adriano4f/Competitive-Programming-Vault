#include <iostream>

using namespace std;

int main(void)
{
  double X, Y; cin >> X >> Y;
  
  if ( abs(double(16)/double(9) - (X/Y)) < 1e-15 ) 
    cout << "Yes" << '\n';
  else
    cout << "No" << '\n';
  return 0;
}
