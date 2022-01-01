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

// O(n)
int jump(vector<int>& nums) {
	int n = size(nums), i = 0, maxReachable = 0, lastJumpedPos = 0, jumps = 0;
	while(lastJumpedPos < n - 1) {  // loop till last jump hasn't taken us till the end
		maxReachable = max(maxReachable, i + nums[i]);  // furthest index reachable on the next level from current level
		if(i == lastJumpedPos) {			  // current level has been iterated & maxReachable position on next level has been finalised
			lastJumpedPos = maxReachable;     // so just move to that maxReachable position
			jumps++;                          // and increment the level
	// NOTE: jump^ only gets updated after we iterate all possible jumps from previous level
	//       This ensures jumps will only store minimum jump required to reach lastJumpedPos
		}            
		i++;
	}
	return jumps;
}

