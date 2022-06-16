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




  
