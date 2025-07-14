# include <bits/stdc++.h>

using namespace std; 

int main () { 
    long long n , Odd_num = 0 ; 
    cin >> n ; 
    if ( n % 2 == 1 ) 
        Odd_num = ( n - 1 ) / 2 + 1 ;
    else 
        Odd_num = n / 2 ; 
    cout << Odd_num ; 
    return 0 ; 
}
