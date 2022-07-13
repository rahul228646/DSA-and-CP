https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, n = nums.size();
        for(auto i : nums) sum+=i;
        int desiredSum = sum - x;
        int len = 0, j = 0, i = 0;
        sum = 0;
        if(desiredSum == 0) return n;
        while(j<n) {
            sum += nums[j];
            while(i<=j && sum>desiredSum) {
                sum-=nums[i++];
            }
            if(sum == desiredSum) {
                len = max(j-i+1, len);
            }
            j++;
        }
        if(len == 0) return -1;
        return n - len;
    }
};

// 1 1 4 2 3
// 1+1+4+2+3 = 11
    
// desiredSum = 11 - 5 = 6
// we need to find the max subarray with sum == 6 this will automatically make
// the rest of the array minimum with sum == 5(x) 
    
// 1 1 4 2 3    
// -----
//  max subarray with sum = 6 is 1 1 4   

