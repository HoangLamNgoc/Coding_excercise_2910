#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 
const int MAXN = 2e5 + 5; 
const int LOG = 31;

struct TRIE {
    struct node {
        int child[2] = {-1, -1};

        long long ex = 0; 
        long long cnt = 0; 

    } trie[MAXN * LOG]; //bug

    int cur; 

    TRIE() { // bug
        cur = 0;
        trie[0].ex = trie[0].cnt = 0;
    }

    void add(long long x) {
        int pos = 0;
        for(int i = LOG - 1; i >= 0; --i) {
            int c = (x >> i) & 1;

            if (trie[pos].child[c] == -1) {
                trie[pos].child[c] = ++cur; 
                trie[cur].ex = 0;
                trie[cur].cnt = 0; 
            }
            
            pos = trie[pos].child[c]; 
            ++trie[pos].cnt; 
        }
        ++trie[pos].ex; 
    }

    long long check(long long x) {
        long long res = 0; 
        long long tar = x ^ ((1LL << LOG) - 1); 
        //bug
        int pos = 0; 

        for(int i = LOG - 1; i >= 0; --i) {
            int c = (tar >> i) & 1; 

            if (trie[pos].child[c] != -1) { 
                res |= (1LL << i); 
                pos = trie[pos].child[c]; 
            }
            else if (trie[pos].child[c ^ 1] != -1) 
                pos = trie[pos].child[c ^ 1];
            else return -1;  
        }
        return res; 
    }
} trie;

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    int n; cin >> n; 

    long long pref[n + 1];
    pref[0] = 0;
    long long ans = 0; 

    trie.add(0);

    for(int i = 1; i <= n; ++i) {
        cin >> pref[i]; 
        pref[i] ^= pref[i - 1]; 

        ans = max(trie.check(pref[i]), ans);
        trie.add(pref[i]);  
    }

    cout << ans; 
}
