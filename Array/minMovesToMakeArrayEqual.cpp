
https://leetcode.com/problems/minimum-moves-to-equal-array-elements/submissions/

// we can increment n-1 elements to make in one move to make all elements equal. this is same as decrementing 1 element one by one to make all elements equal
// therefore for minimum no. of moves we need to make all elements equal to the minimum element

    int minMoves(vector<int>& nums) {
        int n = nums.size(), sum = 0, mn = INT_MAX;
        for(int i = 0; i<n; i++) {
            mn = min(mn, nums[i]);
            sum += nums[i];
        }
        return sum - mn*n; 
    }
