#include <iostream>

using namespace std;

int main()
{
    string dna;
    cin >> dna ;
    long long dem = 1;
    long long res = 1;

    for ( long long i = 1; i < dna.size(); ++i ) {
        if ( dna[i] == dna [i - 1] ) {
            dem++;
            res = max (dem, res);
        }
        else dem = 1;
    }
    cout << res;
    return 0;
}
