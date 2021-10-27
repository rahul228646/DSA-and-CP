
    void transpose(vector<vector<int> >& matrix, int n) 
    { 
        for(int i = 0; i<n; i++) {
            for(int j = i; j<n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    } 
