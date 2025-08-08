#include <iostream> 

using namespace std; 

int main() {
    freopen ("COLORING.INP", "r", stdin); 
    freopen ("COLORING.OUT", "w", stdout); 
    
    int m, n; 
    cin >> m >> n; 
    
    int cl1 = 0, cl2 = 0, cl3 = 0, cl4 = 0; 
    
    for ( int i = 1; i <= m; ++i) {
        for ( int j = 1; j <= n; ++j) { 
            long long chiso = i * j; 
            
            if ( chiso % 5 == 0) 
                cl4++;
                
            else if ( chiso % 3 == 0 ) 
                cl3++; 
            
            else if ( chiso % 2 == 0) 
                cl2++; 
                
            else 
                cl1++; 
        }
    }
    
    cout << cl2 << endl << cl3 << endl << cl4 << endl << cl1;
    return 0; 
}
