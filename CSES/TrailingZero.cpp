# include <iostream>

using namespace std;

int main () {
    long long n, dem = 0 ;
    cin >> n ;
  
    while ( n >= 5) {
        dem += n / 5;
        n /= 5;
    }
  
    cout << dem ;
    return 0 ;
}
