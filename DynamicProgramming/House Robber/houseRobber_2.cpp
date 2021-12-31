
https://leetcode.com/problems/house-robber-ii/
// remove 1st element and run robber 1 , remove last element and run robber 1 then return max of two
class Solution {
public:
    vector<int> dp;
    int robber1(vector<int>& nums, int n) {
        if(n<=0) return 0;
        if(dp[n-1] != -1) return dp[n-1];
        return dp[n-1] = max(solve(nums, n-1), nums[n-1]+solve(nums, n-2));
    }
    int robber2(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0) return 0;
        if(n == 1) return nums[0];

      
        dp = vector<int> (n+1, -1);
        auto temp = nums; 
        nums.erase(nums.begin());
        int x = solve(nums, n-1);
        
        nums = temp;
        nums.pop_back();
        dp = vector<int> (n+1, -1);
        int y = solve(nums, n-1);
        nums = temp; 
        return max(x,y);
    }
};


class Solution {
public:

    int robber1(vector<int>& nums) {
        int n = nums.size();
        int a = 0, b = 0, ans = 0;
        for(int i = 0; i<n; i++) {
            ans = max(b, nums[i]+a);
            a = b;
            b = ans;
        }
        return ans;
    }
    int robber2(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> numsA(nums.begin() + 1, nums.end());
        vector<int> numsB(nums.begin(), nums.end()-1);
        
        return max(robber1(numsA), robber1(numsB));
    }
};
