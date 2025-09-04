#include <iostream>
#include <algorithm>

using namespace std; 

int main() {
	freopen("APARMENTS.INP",r, stdin);
	freopen("APARMENTS.OUT",W, stdout); 
	
  	int n, m; 
  	cin >> n >> m; 

 	long long k; 
	cin >> k;

	long long a[n], b[m];
	for ( int i = 0; i < n; ++i ) cin >> a[i];
	for ( int j = 0; j < m; ++j ) cin >> b[j]; 

	sort(a, a + n); 
	sort(b, b + m);
	int ans = 0; 
	int i = 0; 
	int j = 0;

	while ( i < n && j < m ) {
		if ( abs(a[i] - b[j]) <= k ) {
			++ans; 
			++i;
			++j;
		}
		else if ( b[j] > a[i] + k ) ++i;
		else ++j; 
	}
	cout << ans << endl; 
	return 0;
}
	
