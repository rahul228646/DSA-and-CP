
https://www.geeksforgeeks.org/maximum-contiguous-circular-sum/

    int kadane(int arr[], int n) {
        int maxEndingHere = 0;
        int maxSoFar = INT_MIN;
        for(int i = 0; i<n; i++) {
            maxEndingHere = maxEndingHere + arr[i];
            if(maxSoFar < maxEndingHere) {
                maxSoFar = maxEndingHere;
            }
            if(maxEndingHere < 0) {
                maxEndingHere = 0;
            }
        }
        return maxSoFar;
    } 
    int circularSubarraySum(int arr[], int n){
        
      // kadane's algorith for maximum contiguos subarray sum
        int sumNoWrap = kadane(arr, n);
      // if all elements are negative kadane will give the smallest negative number, that will be the ans
        if(sumNoWrap < 0) return sumNoWrap;
      // for wrap consider {10, -12, 11} 
      // answer should ne 10+11 = 21 
      // we chnage sign & apply kadane {-10, 12, -11} --> 12
      // we add this to the original sum (10-12+11) = 9 --> 21
        int sum = 0;
        for(int i = 0; i<n; i++) {
            sum += arr[i];
            arr[i] = arr[i]*-1;
        }
        int sumWrap = kadane(arr, n) + sum;
        
        // for sum with wrap we are tying to fing min sum subarray and subtracting it from the total sum
        // sumWrap = ToalSum - min sum sub array
        // to find min sum subarray we revert the sign and apply kadanes algo and then we multiply it with -ve sign since we had reverted the signs earlier
        // sumWrap = ToalSum - (- kadane(reverted array)) = ToalSum + kadane(reverted array);
        
        return max(sumWrap, sumNoWrap);
    }


// the above solution doesn't work when all numbers are negative

class Solution {
public:
    int kadane(vector<int>& nums) {
        int maxSoFar = 0, maxTillNow = INT_MIN;
        for(int i = 0; i<nums.size(); i++) {
            maxSoFar += nums[i];
            if(maxSoFar > maxTillNow) {
                maxTillNow = maxSoFar;
            }
            if(maxSoFar < 0) {
                maxSoFar = 0;
            }
        }
        return maxTillNow;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int mxSum = kadane(nums), totalSum = 0, areAllNeg = INT_MIN;
        for(auto &i : nums) {
            areAllNeg = max(areAllNeg, i);
            totalSum+=i;
            i = -1*i;
        }
        int wrapSum = totalSum + kadane(nums);
        if(areAllNeg < 0) return areAllNeg;
        return max(mxSum, wrapSum);
    }
};


