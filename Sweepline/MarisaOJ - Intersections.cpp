//https://marisaoj.com/problem/441

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std; 
const int MAXN = 1e5 + 5; 

struct fenwick {
    vector<int> bit; 
    int n; 

    void init(int _n) {
        n = _n;
        bit.assign(n + 1, 0); 
    }

    void update(int u, int val) {
        for(; u <= n; u += (u & -u)) 
            bit[u] += val; 
    }

    int get(int id) {
        int s = 0; 
        for(; id; id -= (id & -id)) 
            s += bit[id]; 
        return s; 
    }

    int query(int l, int r) {
        return get(r) - get(l - 1); 
    }
} fw;

struct events {
    int x, y1, y2;
    int type;  

    bool operator< (const events& other) const {
        return (x < other.x) || (x == other.x && type < other.type); 
    }
}; 

struct seg {
    int a, b, c; 
}; 

vector<events> ev; 
vector<seg> hor, ver;

long long calc(vector<pair<int,int>> &v) {

    sort(v.begin(), v.end());

    long long ans = 0;

    for(int i = 0; i < (int)v.size(); ++i) {
        int r = v[i].second;

        for(int j = i + 1; j < (int)v.size(); ++j) {

            int l = max(v[j].first, v[i].first);
            int rr = min(r, v[j].second);

            if(l > rr) break;

            ans += rr - l + 1;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n; cin >> n; 

    fw.init(MAXN); 

    for(int i = 0; i < n; ++i) {
        int x1, y1, x2, y2; 
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 == x2) {

            if (y1 > y2) swap(y1, y2);

            ev.push_back({x1, y1, y2, 2});
            ver.push_back({x1, y1, y2});

        }
        else {

            if (x1 > x2) swap(x1, x2);

            ev.push_back({x1, y1, 0, 1}); 
            ev.push_back({x2, 0, y1, 3}); 

            hor.push_back({y1, x1, x2});
        } 
    }

    sort(ev.begin(), ev.end()); 

    long long ans = 0; 

    for(events e : ev) {

        if (e.type == 1) 
            fw.update(e.y1, 1); 

        else if (e.type == 3) 
            fw.update(e.y2, -1); 

        else 
            ans += fw.query(e.y1, e.y2); 
    }

    sort(hor.begin(), hor.end(), [](const seg& a, const seg& b){
        return (a.a < b.a) || (a.a == b.a && a.b < b.b);
    });

    for(int i = 0; i < (int)hor.size();) {

        int j = i;
        vector<pair<int,int>> block;

        while(j < (int)hor.size() && hor[j].a == hor[i].a) {
            block.push_back({hor[j].b, hor[j].c});
            j++;
        }

        ans += calc(block);

        i = j;
    }

    sort(ver.begin(), ver.end(), [](const seg& a, const seg& b){
        return (a.a < b.a) || (a.a == b.a && a.b < b.b);
    });

    for(int i = 0; i < (int)ver.size();) {

        int j = i;
        vector<pair<int,int>> block;

        while(j < (int)ver.size() && ver[j].a == ver[i].a) {
            block.push_back({ver[j].b, ver[j].c});
            j++;
        }

        ans += calc(block);

        i = j;
    }

    cout << ans << '\n'; 
}
