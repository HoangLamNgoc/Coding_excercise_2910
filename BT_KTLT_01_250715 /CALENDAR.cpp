=#include<bits/stdc++.h>

using namespace std;

long long So_ngay (long long m , long long d) {
    long long sochan = ( m - 1 ) / 2 ; 
    long long sole = m / 2 ; 
    long long songay = sochan * 30 + sole * 31 + d - 1; 
    return songay ; 
}

int Thu(long long songay , int w ) {
    int thu = (songay + w - 1) % 7 + 1;
    if ( thu > 7 ) thu -= 7 ;
    return thu ; 
}

int main() {A
    freopen ( "CALENDAR.INP", "r" , stdin ); 
    freopen ( "CALENDAR.OUT", "w" , stdout ); 
    int w ; 
    long long m; 
    int d; 
    cin >> w ;
    cin >> d >> m; 
    int songay = So_ngay (m, d) ; 
    int ket_qua = Thu (songay, w) ; 
    cout << ket_qua ; 
    return 0;
}
