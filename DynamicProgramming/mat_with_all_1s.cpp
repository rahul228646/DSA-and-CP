https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/

// Time : O(m*n) Space : O(m*n)
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        vector<vector<int>> dp(n, vector<int> (m, 0));
        int mx = 0;
        for(int i = 0; i<n; i++) {
            dp[i][0] = mat[i][0];
        }
        for(int i = 0; i<m; i++) {
            dp[0][i] = mat[0][i];
        }
        
        for(int i = 1; i<n; i++) {
            for(int j = 1; j<m; j++) {
                if(mat[i][j] == 0) dp[i][j] = 0;
                else dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                mx = max(mx, dp[i][j]);
            }
        }
        return mx;
    }

// or
// Time : O(m*n) Space : O(1)

    int maxSquare(int n, int m, vector<vector<int>> mat){
        int mx = 0;
        for(int i = 1; i<n; i++) {
            for(int j = 1; j<m; j++) {
                if(mat[i][j] != 0) 
                    mat[i][j] = 1 + min(mat[i-1][j-1], min(mat[i-1][j], mat[i][j-1]));
            }
        }
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                mx = max(mx, mat[i][j]);
            }
        }
        return mx;
    }
