https://leetcode.com/problems/contiguous-array/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> seen;
        int sum = 0, ans = 0;
        seen[0] = -1;
        for(int i = 0; i<nums.size(); i++) {
            (nums[i] == 0) ? sum-- : sum++;
            if(seen.find(sum) != seen.end()) {
                ans = max(i - seen[sum], ans);
                // if val of sum is encountered again this means that in between those there are equal no of ones ans zeros
            }
            else seen[sum] = i;
        }
        return ans;
    }
    
};
