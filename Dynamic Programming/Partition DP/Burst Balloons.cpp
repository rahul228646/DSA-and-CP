// https://leetcode.com/problems/burst-balloons/submissions/
// https://www.youtube.com/watch?v=Yz4LlDSlkns&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=52
class Solution {
public:
    int solve(vector<int>& nums, int i, int j, vector<vector<int>>& dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mn = INT_MIN;
        for(int k = i; k<=j; k++) {
            int cost = nums[i-1]*nums[k]*nums[j+1] + solve(nums, i, k-1, dp) + solve(nums, k+1, j, dp);
            mn = max(mn, cost);
        }
        return dp[i][j] = mn;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return solve(nums, 1, nums.size()-2, dp);
    }
};


// go from bottom to top
// eg = 
//     [3, 1, 5, 8]
//         [8]       ---> burst 8   // elements of [3, 1, 5] will depend on 8 
//         [3, 8]    ---> burst 3  // elements of [1 5] will depend on 3 
//     [3, 5, 8]     ---> burst 5   // elemnts of [3, 1] will depend on 5 not on [8]
//     [3, 1, 5, 8]  ---> burst 1   // elemnts of [3] will depend on 1 not on [5, 8]

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        for(int i = n-1; i>=1; i--) {
            for(int j = i; j<n-1; j++) {
                int mx = INT_MIN;
                for(int k = i; k<=j; k++) {
                    int cost = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    mx = max(mx, cost);
                }
                dp[i][j] = mx;
            }
        }
        return dp[1][n-2];
    }
};


    
