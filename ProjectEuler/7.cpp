#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std; 

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2 ; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true; 
}

int main() {
    int n = 2 ; 
    vector <int> PrimeFactors;
    while ( PrimeFactors.size() <= 10000) {
        if ( isPrime(n)) PrimeFactors.push_back(n);
        n++;
    }
    cout << PrimeFactors[10000]; 
    return 0;
}
