# include <bits/stdc++.h> 

using namespace std ; 

double average_even_digit(int n) {
    vector <int> Even_digit ; 
    while ( n > 0 ) {
        int digit = n % 10 ;
        if ( digit % 2 == 0 ) Even_digit.push_back(digit) ; 
        n = n / 10 ; 
    } 
    if (Even_digit.size() == 0) return -1; 
    double average = (double)accumulate (Even_digit.begin(),Even_digit.end(),0) / Even_digit.size() ;  
    return average ; 
} 

int main () { 
    int n ; 
    cin >> n ; 
    cout << setprecision(3) << average_even_digit(n) ; 
    return 0 ; 
}
        
