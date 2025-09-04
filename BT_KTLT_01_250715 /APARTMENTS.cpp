#include <iostream>
#include <algorithm>

using namespace std; 

int main() {
  	int n, m; 
  	cin >> n >> m; 

 	long long k; 
	cin >> k;

	long long a[n], b[m];
	for ( int i = 0; i < n; ++i ) cin >> a[i];
	for ( int j = 0; j < m; ++j ) cin >> b[j]; 

	sort(a, a + n); 
	sort(b, b + m);

	
