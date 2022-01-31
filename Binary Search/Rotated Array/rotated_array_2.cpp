https://leetcode.com/problems/search-in-rotated-sorted-array-ii/submissions/
time : O(logn) - best, O(n) - worst (because of duplicates)
class Solution {
public:
    
    bool search(vector<int>& nums, int t) {
        int l = 0, h = nums.size()-1, mid = 0;
        while(l<=h) {
            mid = (l+h)/2;
            if(nums[mid] == t) {
                return true;
            }
            else if (nums[l]<nums[mid]) { // left is sorted
                if(nums[l] <= t && t < nums[mid]) { // target lies in left half 
                    h = mid-1;
                }
                else { // target lies in right half 
                    l = mid+1;
                }
            }
            else if (nums[h]>nums[mid]) { // right is sorted
                if(nums[h] >= t && t > nums[mid]) { // target lies in right half 
                    l = mid+1;
                }
                else {  // target lies in left half 
                    h = mid-1;
                }
                
            }
            else { // left or right are equal to mid since duplicated are allowed because of this worst case will be O(n)
                if(nums[l] == nums[mid]) l++; 
                if(nums[h] == nums[mid]) h--;
                
            }
            
        }
        return false;
    }
};
