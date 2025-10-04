#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
  ios_base::sync_with_stdio(0); 
  cin.tie(0);

  int n, m1; 
  cin >> n >> m1;

  bool used[n];
  vector<int> v; 
  int a[n], b[m1]; 
  for(int i = 0; i < n; ++i ) cin >> a[i]; 
  for(int i = 0; i < m1; ++i ) cin >> b[i]; 

  sort(a, a + n);
  for(int m = 0; m < m1; ++m) {
      int it = upper_bound(a , a + n,b[m]) - a;
      it--;
      if (it == -1) v.push_back(-1);
      else { 
        
          v.push_back(a[it]); 
          a[it] = (int)1e9 + 5;
      }
  }
  for (const int& i : v ) cout << i << endl;
  return 0; 
}
