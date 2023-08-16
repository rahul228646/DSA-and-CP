https://leetcode.com/problems/next-permutation/submissions/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2, n = nums.size();
        while(i>=0 && nums[i] >= nums[i+1]) i--;
        if(i>=0) {
            int j = n-1;
            while(nums[j]<=nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        sort(nums.begin()+i+1, nums.end());
    }

};
