class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        if(n == 1) return a[0];
        int lo = 0, hi = n-1, mid = 0, ans = 0;
        while(lo<hi) {
            if(a[lo]<a[hi]) return a[lo];
            mid = (lo+hi)/2;
            
            while(a[mid] == a[hi] && mid != hi) hi--;
            while(a[mid] == a[lo] && mid != lo) lo++;  
            
            if(a[mid]>a[hi]) {
                lo = mid+1;
            }
            else {
                hi = mid;
            }
        }
        return a[lo];
    }
};


    
