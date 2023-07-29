
// https://leetcode.com/problems/wiggle-subsequence/discuss/?currentPage=1&orderBy=most_votes&query=

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return n;
        int prevDiff = nums[1]-nums[0];
        int count = prevDiff != 0 ? 2 : 1;
        for(int i = 2; i<n; i++) {
            int diff = nums[i] - nums[i-1];
            if((diff > 0 && prevDiff <=0) || (diff < 0 && prevDiff >= 0)) {
                count++;
                prevDiff = diff;
            }
        }
        return count;
    }
};

https://leetcode.com/problems/wiggle-subsequence/solutions/2229495/c-o-n-explained/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size=nums.size(), peak=1, valley=1;
        for(int i=1; i<size; ++i){
                 if(nums[i]>nums[i-1]) peak = valley + 1;
            else if(nums[i]<nums[i-1]) valley = peak + 1;
        }
        return max(peak , valley );
    }
};
