
class Solution {
public:
    int smallorequal(int mid, vector<int> arr) {
        int count = 0;
        for(auto i : arr) if(i<=mid) count++;
        return count; 
    }
    int findDuplicate(vector<int>& arr) {
        int hi = arr.size(), lo = 1, mid = 0, ans = 0;
        while(lo<=hi) {
            mid = (lo + hi)/2;
            if(smallorequal(mid, arr) > mid){
                ans = mid;
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }
        return ans;
    }
};

  
