// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size(), m = mat[0].size();
        int l = 0, r = m-1, top = 0, bottom = n-1;
        while(1) {
            
            for(int i = l; i<=r; i++) {
                ans.push_back(mat[top][i]);
            }
            top++;
            
            if(top > bottom) break;
            
            for(int i = top; i<=bottom; i++) {
                ans.push_back(mat[i][r]);
            }
            r--;
            
            if(r<l) break;
            
            for(int i = r; i>=l; i--) {
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
            
            if(top > bottom) break;
            
            for(int i = bottom; i>=top; i--) {
                ans.push_back(mat[i][l]);
            }
            l++;
            
            if(l > r) break;
            
        }
        return ans;
    }
};
