// Time : O(2^T)
https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> ans;
    void solve (vector<int> c, int t, int n, vector<int> &a) {
       if(t == 0) {
           ans.push_back(a);
           return;
       }
       if(n<=0)
           return;
      
       if(c[n-1] <= t) {
           a.push_back(c[n-1]);
           solve(c, t-c[n-1], n, a);
           a.pop_back();
           solve(c, t, n-1, a);
       }
       else {
            solve(c, t, n-1, a);
       }
   }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        int n = c.size();
        vector<int> a;
        solve(c, t, n, a);
        return ans;
    }
};
