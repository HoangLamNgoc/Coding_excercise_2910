#include <iostream> 
#include <cmath>
#include <algorithm> 

using namespace std; 

int main() {
    int n; double S = 0; 
    cin >> n ; 
  	for (int i = 1; i <= n ; ++i)   
      	S = sqrt ( 2 + S ) ;
  	cout << S << endl; 
  	return 0 ; 
}
