#include <iostream>
#include <cstring>
#include <deque>
#include <algorithm>
 
using namespace std;
 
int main() {
	int n, m;
	cin >> n >> m; 
 
	int grid[n][m];
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) 
			cin >> grid[i][j];
 
	int d[n][m]; 
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) d[i][j] = 1e9;
 
	deque<pair<int, int>> q;
	q.push_front({0,0}); 
	d[0][0] = 0;
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0}; 
 
	while (!q.empty()) {
		auto u = q.front();
		q.pop_front(); 
		int r1 = u.first;
		int c1 = u.second; 
 
		for (int i = 0; i < 4; ++i) {
			int r2 = r1 + dx[i];
			int c2 = c1 + dy[i]; 
 
			if ( r2 >= n || r2 < 0 || c2 >= m || c2 < 0) continue; 
			int cost = (i + 1 == grid[r1][c1]) ? 0 : 1; 
			if ( d[r1][c1] + cost < d[r2][c2]) {
				d[r2][c2] = d[r1][c1] + cost; 
				if (cost == 0) q.push_front({r2, c2});
				else q.push_back({r2, c2}); 
			}
		}
	}
 
	cout << d[n - 1][m - 1] << endl; 
	return 0; 
}
