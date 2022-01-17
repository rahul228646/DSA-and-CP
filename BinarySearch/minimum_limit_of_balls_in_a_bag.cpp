https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/

class Solution {
public:
    
    bool isValid(vector<int>& nums, int maxOperations, int penalty) {
        int totalOperationRequired = 0;
        for(auto i : nums) {
            totalOperationRequired += (i-1)/penalty;
            if(totalOperationRequired > maxOperations) return false;
        }
        return true;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = 0, mid = 0;
        for(auto i : nums) high = max(i, high);
        while(low<high) {
            mid = (low+high)/2;
            if(isValid(nums, maxOperations, mid)){
                high = mid; 
            }
            else{
                low = mid+1;
            }
        }
        return high;
        
    }
    
};
