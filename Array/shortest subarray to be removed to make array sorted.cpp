https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
class Solution {
public:

    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), peak = 0, valley = n-1;
        for(int i = 0; i<n-1; i++) if(arr[i]<=arr[i+1]) peak++; else break;
        for(int i = n-2; i>=0; i--) if(arr[i]<=arr[i+1]) valley--; else break;
        
        if(peak == n-1 || valley == 0) return 0;
        // case 1. remove all elements after valley
        int case1 = n-peak-1;
        // case 2. remove all elements before valley
        int case2 = valley;
        
        int ans = min(case1, case2);
      
        // case 3. remove from between
        int i = 0, j = valley;
        while(i<=peak && j<n) {
            if(arr[i]<=arr[j]) {
                // remove elemets between i ans j;
                ans = min(ans, j-i-1);
                i++;
            }
            else {
                j++;
            }
        }
        return ans;
    }
};

// case 3

// [1,2,3,10,4,2,3,5]
//  0 1 2  3 4 5 6 7

// peak = 3
// valley = 5
// inside loop
// try to combine :
// 1 2 3 5 (arr[0]<=arr[5])
// 1 2 2 3 5 (arr[1]<=arr[5])
// 3 3 5
    
