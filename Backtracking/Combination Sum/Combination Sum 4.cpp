// Time : O(N^T)
class Solution {
public:
    int solve(vector<int>& nums, int t, int n) {
        if(t == 0) return 1;
        if(t<0) return 0;
        int ans = 0;
        for(int i = 0; i<n; i++) {
            ans += solve(nums, t-nums[i], n);
        }
        return ans;
    }
    int combinationSum4(vector<int>& nums, int t) {
        int n = nums.size();
        return solve(nums, t, n);
    }
};

// Time : O(t*N)
class Solution {
public:
    int solve(vector<int>& nums, int t, int n, vector<int> &dp) {
        if(t == 0) return 1;
        if(t<0) return 0;
        if(dp[t] != -1) return dp[t];
        int ans = 0;
        for(int i = 0; i<n; i++) {
            ans += solve(nums, t-nums[i], n, dp);
        }
        return dp[t]=ans;
    }
    int combinationSum4(vector<int>& nums, int t) {
        int n = nums.size();
        vector<int> dp(t+1, -1);
        return solve(nums, t, n, dp);
    }
};

// Time : O(t*N)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int t) {
        int n = nums.size();
        vector<uint> dp(t+1, 0);
        dp[0] = 1;
        for(int i = 0; i<=t; i++) {
            for(int j = 0; j<n; j++) {
                if(i>=nums[j]) {
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return dp[t];
    }
};
