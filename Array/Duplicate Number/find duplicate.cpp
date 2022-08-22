// https://leetcode.com/problems/find-the-duplicate-number/submissions/

// Negative Marking
// if the input array is [1,3,3,2] then for 1 , flip the number at index 1 making the array 
// [1,−3,3,2]. Next, for 3 flip the number at index 3 making the array [1,3,3,2]
// [1,−3,3,−2]. Finally, when we reach the second 3 we'll notice that nums[3] is already negative, 
// indicating that 3 has been seen before and hence is the duplicate 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            int cur = abs(nums[i]);
            if(nums[cur]<0) return cur;
            nums[cur] *= -1;
        }
        return -1;
    }
};

// or
// cyclic detection
class Solution {
public:

    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        while(arr[i]>=0) {
            int x = arr[i];
            arr[i] *= -1;
            if(arr[x] < 0) return x;
            i = x;
        }
        return -1;
    }
};

