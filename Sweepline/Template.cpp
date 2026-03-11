#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

const long long INF = 1e18;

struct point {
    long long x, y, id;

    bool operator< (const point& other) const {
        return (x < other.x) || (x == other.x && y < other.y);
    }
};

struct cmp {
    bool operator() (const point& x, const point& y) const {
        return (x.y < y.y) || (x.y == y.y && x.x < y.x);
    }
};

vector<point> p;

long long calc(const point& x, const point& y) {
    return 1LL * (x.x - y.x) * (x.x - y.x) +
           1LL * (x.y - y.y) * (x.y - y.y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;

    for(int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        p.push_back({x, y, i});
    }

    sort(p.begin(), p.end());

    long long sqrtd = calc(p[0], p[1]);

    set<point, cmp> T;

    for(const point &pt : p) {

        long long x = pt.x;
        long long y = pt.y;
        long long id = pt.id;

        long long d = (long long)sqrt(sqrtd);

        point cur = {-INF, y - d, id};

        while(true) {
            set<point, cmp>::iterator it = T.upper_bound(cur);

            if (it == T.end()) break;
            if (it->y > y + d) break;

            if (it->x < x - d) {
                T.erase(it);
                break;
            }

            long long new_d = calc(*it, pt);

            if (new_d < sqrtd) {
                sqrtd = new_d;
                // ghi nhận đáp án mới
            }

            cur = *it;
        }

        T.insert(pt);
    }

    cout << sqrt(sqrtd);
}
