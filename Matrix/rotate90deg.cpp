

    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        for(int i = 0; i<n; i++) {
          reverse(matrix[i].begin(), matrix[i].end());
        }
      // transpose
        for(int i = 0; i<n; i++) {
            for(int j = i; j<n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    } 
