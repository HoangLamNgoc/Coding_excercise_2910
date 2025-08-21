#include <iostream>
#include <vector>

using namespace std; 
long long minval = 1e6;
int n; 
int a[25]; 

void Sol(int i, long long sum, long long total) {
	if ( i == n ) {
		int diff = (long long)abs(2 * sum - total ); 
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
}
