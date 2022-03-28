https://leetcode.com/problems/next-permutation/submissions/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = 0, n = nums.size(), j = 0;
        i = n-2;
        while(i>=0 && nums[i]>=nums[i+1]) i--;
        if(i>=0) {
            int j = n-1;
            while(nums[j]<=nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};
