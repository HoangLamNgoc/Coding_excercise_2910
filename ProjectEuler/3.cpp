#include <iostream>
#include <cmath>
#include <algorithm>

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
 long long n; long long maxval=0;
 cin >> n ; 
 for (long long i=1; i * i <= n;++i)
 {
    if(n%i==0 && i!=n)
    {     long long j = n/i;
           if(isPrime(i) && i> maxval) 
           maxval=i;
           if(isPrime(j) && j> maxval) 
           maxval=j;
    }
 }
cout << maxval << endl; 
    return 0 ;
}

//bool là hàm nhận gtri T/F 
