
// https://www.youtube.com/watch?v=gmPgI05QmIY
// https://leetcode.com/problems/matrix-block-sum/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        // prefix Sum matrix
        int n = mat.size(), m = mat[0].size(); // each element is the sum of (iXj) matrix
        vector<vector<int>> preSum(n, vector<int>(m, 0));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                int a = 0, b = 0, c = 0;
                if(i>0) a = preSum[i-1][j];
                if(j>0) b = preSum[i][j-1];
                if(i>0 && j>0) c = preSum[i-1][j-1];
                preSum[i][j] = mat[i][j] + a + b - c;
            }
        }
        
        auto valid_preSum = [&](int r, int c) {
            if(r < 0 || r >= n || c < 0 || c >= m) return 0;
            return preSum[r][c];
        };
        
        for(int i = 0; i<n; i++) {
            
            int start_r = i-k, end_r = i+k;
            
            for(int j = 0; j<m; j++) {
                
                int start_c = j-k, end_c = j+k;
                
                if(end_r >= n) end_r = n-1;
                if(end_c >= m) end_c = m-1;
               
                mat[i][j] = preSum[end_r][end_c] - valid_preSum(start_r-1, end_c) - 
                    valid_preSum(end_r, start_c-1) + valid_preSum(start_r-1, start_c-1);
            }
        }
        return mat;
    }
};
     // input   preSum     // ans   

     // 1 2 3   1  3  6    12 21 16
     // 4 5 6   5  12 21   27 45 33
     // 7 8 9   12 27 45   24 39 28


