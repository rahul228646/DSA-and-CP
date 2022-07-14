
// read hint
https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/submissions/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxD, minD;
        int j = 0, ans = 0;
        for(int i = 0; i<nums.size(); i++) {

            while(!maxD.empty() && nums[i] > maxD.back()) maxD.pop_back(); 
            while(!minD.empty() && nums[i] < minD.back()) minD.pop_back(); 
            maxD.push_back(nums[i]);
            minD.push_back(nums[i]);
            
            while (!maxD.empty() && !minD.empty() && maxD.front() - minD.front() > limit) {
                if (maxD.front() == nums[j]) maxD.pop_front();
                if (minD.front() == nums[j]) minD.pop_front();
                ++j;
            }
            
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};


    
    
    
