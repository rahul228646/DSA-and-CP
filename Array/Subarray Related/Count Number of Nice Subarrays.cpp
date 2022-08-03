https://leetcode.com/problems/count-number-of-nice-subarrays/discuss/508217/C%2B%2B%3A-Visual-explanation.-O(1)-space.-Two-pointers
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int j = 0, odd = 0, count = 0, total = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & 1) {
                odd++;
                if (odd >= k) {
                    count = 1;
                    while (!(nums[j++] & 1)) count++;
                    total += count;
                }
            } else if (odd >= k) total += count;
        }
        return total;
    }
};


or
    
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
