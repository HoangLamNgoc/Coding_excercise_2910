#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std; 
const int MAXN = 2e5 + 5;
 
struct prj {
    int start, end, rew; 
    prj() {}; 
    prj(int ss, int ee, int rr) : start(ss), end(ee), rew(rr) {}; 
}; 
 
bool ss (const prj& x, const prj& y) {
    return x.end < y.end || (x.end == y.end && x.start < y.start); 
}
 
bool compare(const prj& x, int y) {
    return x.end < y; 
}
 
long long dp[MAXN];
prj projects[MAXN];  
 
int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
 
    int num; cin >> num;
 
    for(int i = 1; i <= num; ++i) cin >> projects[i].start >> projects[i].end >> projects[i].rew; 
    sort(projects + 1, projects + num + 1, ss);
 
 
    dp[0] = 0; 
    dp[1] = projects[1].rew; 
    for(int i = 2; i <= num; ++i) {
        int a = lower_bound(projects + 1, projects + num + 1, projects[i].start, compare) - projects - 1; 
        if (a) {
            dp[i] = max(dp[i - 1], dp[a] + projects[i].rew); 
        }
        else dp[i] = max(dp[i - 1], 1LL * projects[i].rew); 
    }
    cout << dp[num] << "\n"; 
    return 0; 
}
