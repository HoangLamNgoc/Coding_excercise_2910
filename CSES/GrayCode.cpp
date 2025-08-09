#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


void Sol(vector<string>& v, int num) {
    if ( num == 0) {
        for (const string& s : v)
            cout << s << endl;
        return;
    }

    vector<string> v_copy = v;
    reverse(v_copy.begin(),v_copy.end());

    vector <string> new_v;

    for ( const string& s : v)
        new_v.push_back(string ("0") + s);

    for ( const string& s : v_copy)
        new_v.push_back(string("1") + s);

    Sol (new_v, num - 1);
}


int main () {
    int n;
    cin >> n;

    vector<string> v;
    v.push_back("");

    Sol(v,n);
    return 0;

}
