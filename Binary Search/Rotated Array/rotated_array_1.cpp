https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/
// o(logn)
class Solution {
public:
    // no duplicates
    int search(vector<int>& nums, int t) {
        int n = nums.size();
        int lo = 0, hi = n-1, mid = 0;
        while(lo<=hi) {
            mid = (lo+hi)/2;
            // cout<<lo<<" "<<hi<<" "<<mid<<endl;
            if(nums[mid] == t) {
                return mid;
            }
            else if (nums[lo] <= nums[mid]) { //left half is in order
                if(nums[lo] <= t && t < nums[mid]) {
                    hi = mid-1;
                }
                else {
                    lo = mid+1;
                }
            }
            else if (nums[hi] > nums[mid]) { //right half is in order
                if(nums[mid] < t && t <= nums[hi]) {
                    lo = mid+1;
                }
                else {
                    hi = mid-1;
                }
            }
  
        }
        return -1;
    }
};
// or

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
            int l = 0, r = nums.size()-1;
            while(l <= r)
            {
                int mid = (r - l)/2 + l;
                int comparator = nums[mid];
                // Checking if both target and nums[mid] are on same side.
                if((target < nums[0]) && (nums[mid] < nums[0]) || (target >= nums[0]) && (nums[mid] >= nums[0]))
                    comparator = nums[mid];
                else
                {
                    // Trying to figure out where nums[mid] is and making comparator as -INF or INF
                    if(target <nums[0])
                        comparator = INT_MIN;
                    else 
                        comparator = INT_MAX;

                }
                if(target == comparator) return mid;
                if(target > comparator)            
                    l = mid+1;            
                else
                    r = mid-1;

            }
            return -1;
    }
};
