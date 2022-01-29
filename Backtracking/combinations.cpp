https://leetcode.com/problems/combinations/

class Solution {
public:
    vector<vector<int>> ans;
    void solve(int idx, int n, int k, vector<int>& curr) {
        if(curr.size()==k) {
            ans.push_back(curr);
            return ;
        }
        for(int i = idx; i<=n; i++) {
            curr.push_back(i);
            solve(i+1, n, k, curr);
            curr.pop_back();
        }
        return ;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        solve(1, n, k, curr);
        return ans;
    }
};


