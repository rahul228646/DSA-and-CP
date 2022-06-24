// https://leetcode.com/problems/reverse-pairs/submissions
// Time : O(logN * ( O(N) + O(N) ) ) Space : o(n)
class Solution {
public:
    int modifiedMerge(vector<int>& nums, int lo, int mid, int hi) {
        int count = 0;
        int j = mid+1;
        for(int i = lo; i<=mid; i++) { // O(N)
            while(j<=hi && nums[i] > 2LL*nums[j]) {
                j++;
            }
            count += (j-(mid+1));
        }
        
        // normal merge 
        vector<int> temp;
        int left = lo, right = mid+1;
        while(left<=mid && right<=hi) { // O(N) mergin
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            }
            else {
                 temp.push_back(nums[right++]);
            }
        }
        while(left<=mid) temp.push_back(nums[left++]);
        while(right<=hi) temp.push_back(nums[right++]);
        
        for(int i = lo; i<=hi; i++) {
            nums[i] = temp[i-lo];
        }
        
        return count;
        
    }
    
    int modifiedMergeSort(vector<int>& nums, int lo, int hi) { // logN levels
        if(lo>=hi) return 0;
        int mid = (lo+hi)/2;
        int inv = 0;
        inv += modifiedMergeSort(nums, lo, mid);
        inv += modifiedMergeSort(nums, mid+1, hi);
        inv += modifiedMerge(nums, lo, mid, hi);
        return inv;
    }
    int reversePairs(vector<int>& nums) {
        return modifiedMergeSort(nums, 0, nums.size()-1);
    }
};





