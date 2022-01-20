// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
// time : O(logn)

class Solution {
public:
    int findMin(vector<int>& a) {
        int lo = 0, hi = a.size()-1, mid = 0;
        while (lo<hi) {
            if(a[lo]<a[hi]) return a[lo]; //array is sorted
            mid = (lo+hi)/2;
            
            if(a[lo]<=a[mid]) { // array is rotated in the second half (3 4 5 1 2 )
                lo = mid+1;
            }
            else { // array is rotated in the first half  4 5 1 2 3 
                hi = mid;
            }
        }
        return a[lo];
    }
};


