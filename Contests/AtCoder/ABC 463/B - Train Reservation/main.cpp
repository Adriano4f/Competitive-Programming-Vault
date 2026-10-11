#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  size_t N; char in; cin >> N >> in;
  size_t X = size_t(in - 'A');
  for ( size_t i = 0; i < N; ++i )
  {
    string input; cin >> input;
    if ( input[X] == 'o' )
    {
      cout << "Yes" << '\n';
      return 0;
    }
  }
 
  cout << "No" << '\n';
  return 0;
}
