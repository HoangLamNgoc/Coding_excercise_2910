struct matrix {
    int n, m; 
    vector<vector<int>> data; 

    matrix() {}; 
    matrix(int r, int c) : data(r, vector<int>(c, 0)), n(r), m(c) {}; 

    int& operator() (int i, int j) {
        return data[i][j]; 
    }

    int operator() (int i, int j) const {
        return data[i][j]; 
    }

    int row() { return n; } 

    int col() { return m; }

    friend ostream& operator << (ostream& out, const matrix& a) {
        for(int i = 0; i < a.n; ++i) {
            for(int j = 0; j < a.m; ++j) {
                out << a(i, j) << ' '; 
            }
            out << '\n'; 
        }
        return out; 
    } 

    matrix operator * (const matrix& a) const {
        matrix c(n, a.m);  
        for(int i = 0; i < n; ++i) 
            for(int j = 0; j < m; ++j)
                for(int k = 0; k < a.m; ++k)
                    c[i][j] += data[i][k] * a.data[k][j]; 
        return c; 
    }
}; 
