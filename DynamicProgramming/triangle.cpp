https://leetcode.com/problems/triangle/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<t[i].size(); j++) {
                int curr_idx = INT_MAX, prev_idx = INT_MAX;
                if(j == 0) curr_idx = t[i-1][j];
                else if(j == t[i].size()-1) prev_idx = t[i-1][j-1];
                else {
                    curr_idx = t[i-1][j];
                    prev_idx = t[i-1][j-1];
                }
                t[i][j] += min(curr_idx, prev_idx);
            }
        } 
        
        for(auto i : t) {
            for(auto j : i) {
                cout<<j<<" ";
            }
            cout<<endl;
        }
        
        int ans = INT_MAX;
        for(auto i : t[n-1]) ans = min(ans, i);
        return ans;
    }
};

   2              2
  3 4            5 6 
 6 5 7         11 10 13 
4 1 8 3       15 11 18 16 
    
 
ans = 11


     
     
