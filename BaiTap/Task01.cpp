#include <iostream> 
#include <cmath>
#include <algorithm> 

using namespace std; 

int main() {
    int n ; double S = 0 ; 
    cin >> n ; 
    for (int i = 1 ; i <= n ; ++i ) {
    if( i % 2 == 0)
        S= S-1/sqrt(i);
    else 
        S= S+1/sqrt(i); 
    }
    cout << S << endl ; 
    return 0; 
}
    
      

