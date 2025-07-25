#include<bits/stdc++.h>

using namespace std;

long long So_ngay (long long m , int d) {
    long long songay = 0 ; 
    if ( m % 2 != 0 ) songay = 30 * ( m - 1 )  + (( m - 1 ) / 2 ) + d ; 
    else songay = 30 * ( m - 1 ) + ( ( m - 1 ) / 2 ) + 1 + d ;
    return songay ; 
}

int Thu(long long songay , int w ) {
    int dem = songay % 7 ; 
    int thu = (dem + w - 1) % 7 ; 
    return thu ; 
}

int main() {
    freopen ( "CALENDAR.INP", "r" , stdin ); 
    freopen ( "CALENDAR.OUT", "w" , stdout ); 
    int w ; 
    long long m; 
    int d; 
    cin >> w ;
    cin >> m >> d; 
    int songay = So_ngay (m, d) ; 
    int ket_qua = Thu (songay, w) ; 
    cout << ket_qua ; 
    return 0;
}
