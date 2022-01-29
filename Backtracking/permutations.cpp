// https://leetcode.com/problems/permutations/submissions/

// Time Complexity: O(n*n!)

class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int n, int idx) {
        if(idx == n) {
            ans.push_back(nums);
            return;
        }
        for(int i = idx; i<=n; i++) {
            swap(nums[idx], nums[i]);
            solve(nums, n, idx+1);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums, nums.size()-1, 0);
        return ans;
    }
};
