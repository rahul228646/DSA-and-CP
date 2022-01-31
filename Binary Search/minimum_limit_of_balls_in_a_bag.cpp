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

// mid depicts the value of penalty is valid determines if this is the max penalty possible, for MaxOperations
// For example, the mid = 3,
// A[i] = 2, we split it into [2], and operations = 0
// A[i] = 3, we split it into [3], and operations = 0
// A[i] = 4, we split it into [3,1], and operations = 1
// A[i] = 5, we split it into [3,2], and operations = 1
// A[i] = 6, we split it into [3,3], and operations = 1
// A[i] = 7, we split it into [3,3,1], and operations = 2

// The number of operation we need is (a - 1) / mid

// If the total operation > max operations,
// the size of bag is too small,
// we set left = mid + 1

// Otherwise,
// this size of bag is big enough,
// we set right = mid

// We return the final result,
// where result = left = right.

