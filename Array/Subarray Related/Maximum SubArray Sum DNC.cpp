// https://leetcode.com/problems/maximum-subarray/

// Time : O(N*logN) 

class Solution {
public:
    int findMaxSumSubArray(vector<int>& nums, int left, int mid, int right) {
        int sum = 0;
        int leftSubArraySum = INT_MIN, rightSubArraySum = INT_MIN;
        for(int i = mid; i>=left; i--) {
            sum += nums[i];
            leftSubArraySum = max(leftSubArraySum, sum);
        }
        sum = 0;
        for(int i = mid+1; i<=right; i++) {
            sum += nums[i];
            rightSubArraySum = max(rightSubArraySum, sum); 
        }
        return leftSubArraySum + rightSubArraySum;
    }
    int findMaxSum(vector<int>& nums, int left, int right) {
        if(left == right) return nums[left];
        if(left>right) return 0;
        int mid = (left+right)/2;
        int leftSum = findMaxSum(nums, left, mid);
        int rightSum = findMaxSum(nums, mid+1, right);
        return max(leftSum, max(rightSum, findMaxSumSubArray(nums, left, mid, right)));
    } 
    int maxSubArray(vector<int>& nums) {
       return findMaxSum(nums, 0, nums.size()-1);
    }
};


