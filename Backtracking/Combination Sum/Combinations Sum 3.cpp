// Time : O(2^k) k is size of temp

class Solution {
public:
    vector<vector<int>> ans;
    void solve(int k, int n, int num, vector<int> &temp) {
        if(temp.size()>k) return ;
        if(n == 0 && temp.size()==k) {
            ans.push_back(temp);
            return;
        }
        if(num>9) return ;
        temp.push_back(num);
        solve(k, n-num, num+1, temp);
        temp.pop_back();
        solve(k, n, num+1, temp);
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        solve(k,n, 1, temp);
        return ans;
    }
};
