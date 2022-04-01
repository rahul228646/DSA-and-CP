https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/submissions/

https://www.youtube.com/watch?v=pW5fvwnZ1TA&list=PL-Jc9J83PIiFJRioti3ZV7QabwoJK6eKe&index=14

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), count = 0;
        for(int i = 0; i<n; i++) {
            int val = arr[i];
            for(int k = i+1; k<n; k++) {
                val ^= arr[k];
                if(!val) count += (k-i);
            }
        }
        return count;
    }
};
