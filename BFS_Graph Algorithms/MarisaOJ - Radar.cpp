#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
const double maxn = 1e6 + 9; 
vector<double> x, y;
int n;  

bool bfs(double R) {
	vector<bool> vis(n, false);

	queue<int> q; 
	q.push(0);
	vis[0] = true; 
    int cnt = 1; 
	
	while (!q.empty()) {
		int u = q.front(); q.pop(); 
		for( int v = 0; v < n; ++v) {
			if(!vis[v]) {
				double dx = x[u] - x[v];
				double dy = y[u] - y[v]; 
				
				if (dx * dx + dy * dy <= (2 * R) * (2 * R)) {
					vis[v] = true; 
					cnt++; 
					q.push(v); 
				}
			}
		}
	}
	
	if (cnt == n) return true;
	return false;
}

int main() {
	cin >> n; 
	x.resize(n); 
    y.resize(n); 
	for(int i = 0; i < n; ++i) cin >> x[i] >> y[i]; 
	
	double hi = 1e9, lo = 0;
    double ans = 1e9;
	
	for(int i = 0; i <= 60; ++i) {
		double mid = ( hi + lo )/ 2; 
		if(bfs(mid)) {
			hi = mid; 
			ans = min(ans,mid);
		}
		else lo = mid; 
	}
	cout << fixed << setprecision(6) << ans << endl; 
	return 0; 
}
