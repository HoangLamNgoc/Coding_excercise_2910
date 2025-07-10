
#include <iostream> 
#include <cmath>
#include <algorithm> 
using namespace std; 

int main()
{
  int n; double S=0;
  cin >> n ;
	for ( int i = n ; i >= 2 ; --i )
 	{ 
        S= 1/(i+S); 
	}
  double s=1+S;
 cout << s << endl ; 
 return 0; 
 }
