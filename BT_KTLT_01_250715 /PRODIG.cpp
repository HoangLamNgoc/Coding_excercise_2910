#include <iostream>
using namespace std;

int main() { 
    long long n; 
    cin >> n; 
    
    for (long long m = 1; m <= n; ++m) { 
        long long copy_n = n;
        long long tmp = m; 
        bool kiem = true;
        
        while (tmp > 0) { 
            long long digit = tmp % 10; 
            
            if (digit == 0 || copy_n % digit != 0) { 
                kiem = false; 
                break; 
            } 
            copy_n /= digit; 
            tmp /= 10; 
        }
        
        if (kiem && copy_n == 1 && m != n) { 
            cout << m; 
            break; 
        }
    }
    return 0; 
}
