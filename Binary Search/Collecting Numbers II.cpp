#include <iostream>
#include <algorithm>
using namespace std;

int T;

void Sol(int x, int y, int a[], int p[]) {
    swap(a[x], a[y]);    // swap giá trị ở 2 vị trí
    p[a[x]] = x; // cập nhật vị trí mới của giá trị a[x]
    p[a[y]] = y; // cập nhật vị trí mới của giá trị a[y]

    int r = 1;
    for (int i = 2; i <= T; ++i)
        if (p[i] < p[i - 1])
            r++;
    cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> T >> m;

    int a[T + 5], pos[T + 5];
    for (int i = 1; i <= T; ++i) {
        int x; cin >> x;
        a[i] = x;
        pos[x] = i;
    }

    while (m--) {
        int x, y;
        cin >> x >> y;
        Sol(x, y, a, pos);
    }

    return 0;
}
