#include <bits/stdc++.h>       

using namespace std;  

int main () {
    int n , dem = 0 , tong = 0 ;
    cin >> n ;
    n = abs(n) ;
    while (n > 0) {
        dem = dem + 1 ; 
        if ( dem % 2 == 0 ) tong = tong + n % 10 ;
        n = n / 10 ;
    }
    cout << tong ; 
    return 0; 
}
		
