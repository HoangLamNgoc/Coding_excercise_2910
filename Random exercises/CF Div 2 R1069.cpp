#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    int T; cin >> T; 

    while(T--) {
        string s, q; cin >> s >> q; 

        int q1 = q.length();
        int s1 = s.length(); 

        if (s1 > q1) {
            cout << "Impossible" << '\n'; 
            continue; 
        } 

        vector<int> freqs(26, 0), freqq(26, 0); 
        for(int i = 0; i < s1; ++i) {
            freqs[int(s[i] - 'a')]++;
        } 
        for(int i = 0; i < q1; ++i) {
            freqq[q[i] - 'a']++;
        }

        bool ok = 1;
        for(int i = 0; i < 26; ++i) {
            if (freqs[i] > freqq[i]) {
                ok = 0; 
                break; 
            } 
            else {
                freqq[i] -= freqs[i]; 
            }
        }
        if (!ok) {
            cout << "Impossible" << '\n';
            continue;  
        }
        
        if (s1 == q1) {
            cout << s << "\n"; 
            continue; 
        } 
        int cur = 0;
        string ans = "";  
        for(int i = 0; i < 26; ++i) {
            while(cur < s1 && s[cur] <= i + 'a') {
                ans += s[cur]; 
                cur++; 
            } 
            
            while(freqq[i]) {
                ans += char(i + 'a'); 
                --freqq[i];
            }
        }
        cout << ans << '\n'; 
    }
}
