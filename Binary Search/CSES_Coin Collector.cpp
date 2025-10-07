#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int pos[n + 5];
    for(int i = 0; i < n; ++i ) {
        int x; cin >> x;
        pos[x] = i;
    }
    int r = 1;
    for (int i = 2; i <= n; ++i)
        if (pos[i] < pos[i - 1]) r++;

    cout << r << endl;
    return 0;
}

//https://www.notion.so/Collecting-Numbers-2858b4d60bef80939783d97d951d727b?source=copy_link
