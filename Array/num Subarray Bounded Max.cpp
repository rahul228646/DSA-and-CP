// https://www.youtube.com/watch?v=My3pobBPtbA
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int i = 0, j = 0, count = 0, prevCount = 0;
        while(j<nums.size()) {
            if(nums[j] > right) {
                i = j+1;
                prevCount = 0;
            }
            else if(nums[j]<left) {
               count += prevCount;  
            }
            else {
                prevCount = j-i+1; 
                count += prevCount;
           
            }
            // cout<<count<<endl;
            j++;
        }

        return count;
    }
};
