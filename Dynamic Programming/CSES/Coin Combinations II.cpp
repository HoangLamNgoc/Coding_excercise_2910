for(int j = 1; j <= num; ++j) {
        cout << j << '\n'; 
        for(int i = 1; i <= am; ++i) {
            if (a[i] <= j) { 
                ways[j] += ways[j - a[i]]; 
                ways[j] %= LOG;
                cout << a[i] << '\n'; 
                for(int k = 1; k <= num; ++k) {
                    cout << ways[k] << ' '; 
                }
                cout << '\n'; 

            }
            cout << '\n';   
        }
    } 
    cout << ways[num] % LOG; 
