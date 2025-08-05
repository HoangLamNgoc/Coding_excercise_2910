#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
#define maxN 1e6 + 5;

void Sol(ll n, ll dem) {
    int hang = 1;
    vector <ll> ans;
    vector <ll> ans1;

    dem = dem / 2;

    for ( ll i = n; i >= 1; --i ) {
        if ( dem >= i ) {
            dem -= i;
            ans.push_back(i);
        }
        else ans1.push_back(i);
    }

    cout << ans.size() << endl;
    for (ll i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';

    cout << endl << ans1.size() << endl;
    for (ll i = 0; i < ans1.size(); ++i)
        cout << ans1[i] << ' ';
}

int main()
{
    ll n;
    cin >> n;

    ll dem = 0;

    for ( ll i = 1; i <= n; ++i)
        dem += i;

    if ( dem % 2 == 0 ) {
        cout << "YES" << endl;
        Sol(n,dem);
    }
    else cout << "NO" << endl;
    return 0;
}
