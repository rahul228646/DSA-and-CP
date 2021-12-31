https://leetcode.com/problems/delete-and-earn/

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
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;

        //take the total sum by each number
        vector<int> sum(n, 0);
        vector<int> dp(n, 0);

        for(auto num: nums){
            sum[num] += num;
        }

        return rob(sum);
    }
};
