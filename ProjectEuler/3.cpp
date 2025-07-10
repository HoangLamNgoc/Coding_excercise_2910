#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std; 

bool isPrime(long long x) {
    if (x < 2) return false;
    for (long long y = x; y * y <= x; ++y) 
        if (x % y == 0) return false;
    return true; 
}

int main() {
    cin >> n;
    vector<int> primeFactors; 
    for (long long i = 1; i * i <= n; ++i) {
        if(n % i == 0) {    
            long long j = n / i;
            if(isPrime(i)) primeFactors.push_back(i);
            if(isPrime(j)) primeFactors.push_back(j);   
        }
    }
    cout << *max_element( primeFactors.begin(), primeFactors.end()); 
    return 0 ;
}

//bool là hàm nhận gtri T/F 
