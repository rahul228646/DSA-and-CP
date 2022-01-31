https://leetcode.com/problems/jump-game/submissions/

class Solution {
public:

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int step = nums[0];
        for(int i = 1; i<n; i++) {
            step--;
            if(step<0) return false;
            step = max(nums[i], step);
        }
        return true;
    }
};
