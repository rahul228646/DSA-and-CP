// Time : O(2^N)
class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int n, int i, vector<int> &temp) {
        ans.push_back(temp);
        for(int j = i; j<n; j++) {
            temp.push_back(nums[j]);
            solve(nums, n, j+1, temp);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        solve(nums, n, 0, temp);
        return ans;
    }
};
