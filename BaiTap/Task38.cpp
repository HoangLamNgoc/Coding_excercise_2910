#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std; 

bool isPrime(int n) {
    for (int i = 2 ; i * i <= n; ++i) 
        if (n % i == 0) return false;
    return true; 
}

int main() {
    cin >> num;
    set<int> primeFactors; 
    for (int i = 2 ; i * i <= num; ++i) {
        if(num % i == 0) {    
            int j = num / i;
            if(isPrime(i)) primeFactors.insert(i);
            if(isPrime(j)) primeFactors.insert(j);   
        }
    }
    for (int n : primeFactors ) 
        cout << n << " " ; 
    return 0 ;
}
