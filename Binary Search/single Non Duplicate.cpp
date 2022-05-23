// https://leetcode.com/problems/single-element-in-a-sorted-array/submissions/
class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        
        int l = 0, r = arr.size()-1, mid = 0;
        if(arr.size()==1){
            return arr[0];
        }

        if(arr[l]!=arr[l+1]){
            return arr[l];
        }

        if(arr[r]!=arr[r-1]){
            return arr[r];
        }

        while(l<=r) {
            mid = (l+r)/2;
            if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) return arr[mid];
            else if( (mid % 2 == 0 && arr[mid] == arr[mid+1]) ||  (mid % 2 == 1 && arr[mid] == arr[mid-1]) ) {
               l = mid+1; 
                // if all elements before a particular index were to be repeated twice then at even index we would have the first occurance and at odd we would have the second occurance of the element 
            }
            else {
                r = mid;
            }
        }
        return -1;
    }
};
