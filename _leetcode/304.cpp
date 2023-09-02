class NumMatrix {
public:
    int pf[1000][1000] = {0};
    
    void fill(int i, int j, int & val) {
        i++; j++;
        pf[i][j] = pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1] + val;
    }
    
    NumMatrix(vector<vector<int> > & a) {
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a[0].size(); j++) {
                fill(i, j, a[i][j]);
            }
        }

    }
    


    int sumRegion(int i1, int j1, int i2, int j2) {
        i1++; j1++; i2++; j2++;
        return pf[i2][j2] - pf[i1 - 1][j2] - pf[i2][j1 - 1] + pf[i1 - 1][j1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */