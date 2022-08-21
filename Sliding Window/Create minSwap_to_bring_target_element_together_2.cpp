
// here array is circular array of 1's and 0's
// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/submissions/  

class Solution {
public:
    int minSwapTogether(vector<int>& arr, int t) {
        
        int n = arr.size(), targetCount = 0, maxTargetCount = 0;
        
        for(auto i : arr) if(i == t) targetCount++;
        
        int windowSize = targetCount, windowTargetCount = 0;
        
        for(int i = 0; i<windowSize; i++) if(arr[i] == t) windowTargetCount++;
        
        int i = 0, j = windowSize;
        
        maxTargetCount =  windowTargetCount;
        while(j<n-1) {
            if(arr[i] == t) windowTargetCount--;
            if(arr[j] == t) windowTargetCount++;
            maxTargetCount = max(windowTargetCount, maxTargetCount);
            i++;
            j++;
        }
        
        return targetCount - maxTargetCount;
    } 
    int minSwaps(vector<int>& arr) {
        int oneSwap =  minSwapTogether(arr, 1);
        // cout<<oneSwap<<endl;
        int zeroSwap =  minSwapTogether(arr, 0);
        // cout<<zeroSwap<<endl;
        return min(oneSwap, zeroSwap);
    }
};

// or

int minSwaps(vector<int>& nums) {
    int ones = count(begin(nums), end(nums), 1), n = nums.size(), res = n;
    for (int i = 0, j = 0, cnt = 0; i < n; ++i) {
        while (j - i < ones)
            cnt += nums[j++ % n];
        res = min(res, ones - cnt);
        cnt -= nums[i];
    }
    return res;
}
