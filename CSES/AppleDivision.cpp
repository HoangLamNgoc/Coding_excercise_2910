//ĐỆ QUY : 
#include <iostream>
#include <vector>

using namespace std; 
long long minval = 1e9;
int n; 
long long a[25]; 

void Sol(int i, long long sum, long long total) {
	if ( i == n ) {
		long long diff = abs(2 * sum - total ); 
		minval = min(diff, minval); 
		return; 
	}
		
	Sol(i + 1, sum, total);
	Sol ( i + 1; sum + a[i], total); 
}

int main() {
	cin >> n; 
	long long total = 0; 
	for ( int i = 0; i < n; ++i) {
		cin >> a[i]; 
		total += a[i]; 
	}
	Sol (0,0,total); 
	cout << minval << endl; 
	return 0;
}

// TOÁN TỬ BIT 
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long a[n];
    long long total = 0;
    for ( int i = 0; i < n; ++i) {
        cin >> a[i];
        total += a[i];
    }

    long long dif = 1e9;
    for ( int mask = 0; mask < ( 1 << n ) ; ++mask) {
        long long sum = 0;
        for ( int j = 0; j < n; ++j) {
            if ( mask & ( 1 << j )) {
                sum += a[j];
                dif = min( dif,abs(total - 2 * sum));
            }
        }
    }
    cout << dif << endl;
	return 0; 
}
