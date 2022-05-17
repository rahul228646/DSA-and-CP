https://leetcode.com/problems/subarray-product-less-than-k/submissions/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int prod = 1, ans = 0, left = 0;
        for(int right = 0; right<nums.size(); right++) {
            prod *= nums[right];
            while(prod >= k) prod /= nums[left++];
            ans += right - left +1;
        }
        return ans;
    }
};

// If we start at the 0th index, [10,5,2,6], the number of intervals is obviously 1.
    
// If we move to the 1st index, the window is now [10,5,2,6]. The new intervals created are [5] and [10,5], so we add 2.
    
// Now, expand the window to the 2nd index: [10,5,2,6]. The new intervals are [2], [5,2], and [10,5,2], so we add 3.
    
// The pattern should be obvious by now; we add right - left + 1 to the output variable every loop!
