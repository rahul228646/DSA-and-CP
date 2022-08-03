    
class Solution {
public:
    int slidingWindow(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size(), res = 0, odd = 0;
        for(;j<n;j++) {
            if(nums[j]&1) odd++;
            while(odd>k) {
                if(nums[i++]&1) odd--;
            }
            res = j-i+1;
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        // k exactly = at most k - at most k-1
        return slidingWindow(nums, k) - slidingWindow(nums, k-1)
    }
    
    
};
