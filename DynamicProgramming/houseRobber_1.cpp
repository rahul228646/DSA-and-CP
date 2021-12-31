https://leetcode.com/problems/house-robber/

class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums, int n) {
        if(n<=0) return 0;
        if(dp[n-1] != -1) return dp[n-1];
        return dp[n-1] = max(solve(nums, n-1), nums[n-1]+solve(nums, n-2));
    }
    int rob(vector<int>& nums) {
        dp = vector<int> (nums.size()+1, -1);
        return solve(nums, nums.size());
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp = vector<int> (nums.size()+1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i<=n; i++) {
            dp[i] = max(dp[i-1], nums[i-1]+dp[i-2]);
        }
        return dp[n];
    }
};
