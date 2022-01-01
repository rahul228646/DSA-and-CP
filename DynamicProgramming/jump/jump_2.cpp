https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int solve(vector<int>& nums, int n, int pos) {
        if(pos >= n-1) return 0;
        int minJumps = 1001; 
	    for(int j = 1; j <= nums[pos]; j++)  
		    minJumps = min(minJumps, 1 + solve(nums,n, pos + j));        
	    return minJumps;
    
    }
    int jump(vector<int>& nums) {
        return solve(nums, nums.size(), 0);
    }
};


// memo 
// O(n^2) 

class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums, int n, int pos) {
        if(pos >= n-1) return 0;
        
        if(dp[pos] != 10001) return dp[pos];
        
	    for(int j = 1; j <= nums[pos]; j++)  
		    dp[pos] = min(dp[pos], 1 + solve(nums, n, pos + j));  
        
	    return dp[pos];
    
    }
    int jump(vector<int>& nums) {
        dp=vector<int>(nums.size(), 10001);
        return solve(nums, nums.size(), 0);
    }
};


