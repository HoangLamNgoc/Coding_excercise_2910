#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std; 

bool isPrime(int x)
{
    if (x<2) return false;
    if( x == 2) return true ; 
    if( x%2 == 0) return false ; 
    for (int t=3;t * t <=x; ++t)
        { 
            if (x%t == 0) 
            return false;
        }
        return true; 
}

int main() {
 long long n;
 cin >> n ; 
 vector<int> primeFactors; 
 for (long long i=1; i * i <= n;++i)
 {
    if(n%i==0)
    {     long long j = n/i;
           if(isPrime(i))
               primeFactors.push_back(i);
           if(isPrime(j))
               primeFactors.push_back(j);   
    }
 }
   long long maxval= *max_element( primeFactors.begin(), primeFactors.end());
cout << maxval << endl; 
    return 0 ;
}

//bool là hàm nhận gtri T/F 
