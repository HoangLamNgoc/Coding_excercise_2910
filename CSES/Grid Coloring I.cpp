#include <iostream>
#include <string>
#include <set>
 
using namespace std;
 
int main()
{
    int n, m;
    cin >> n >> m;
 
    string a[n];
    for(string& s : a) cin >> s;
 
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            set<char> s;
            if(i != 0) s.insert(a[i - 1][j]);
            if(j != 0) s.insert(a[i][j - 1]);
            s.insert(a[i][j]);
            for(char x = 'A'; x <= 'D'; ++x) {
                if(!s.count(x)) {
                    a[i][j] = x;
                }
            }
        }
        cout << a[i] << endl;
    }
    return 0;
}
