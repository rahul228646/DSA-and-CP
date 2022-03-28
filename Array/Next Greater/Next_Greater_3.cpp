https://leetcode.com/problems/next-greater-element-iii/submissions/

class Solution {
public:
    bool nextPermutation(string& nums) {
        int i = nums.size()-1;
        while (i > 0 && nums[i-1] >= nums[i]) i--;
        if (i == 0) return false;
        
        int j = nums.size()-1;
        while (j > 0 && nums[j] <= nums[i-1]) j--;
        swap(nums[j], nums[i-1]);
        reverse(nums.begin()+i, nums.end());
        return true;
    }
    int nextGreaterElement(int n) {
        string arr = to_string(n);
        auto val = nextPermutation(arr);
        auto res = stoll(arr);
        if(res > INT_MAX || n >= res || !val) return -1;
        return res;
    }
};

