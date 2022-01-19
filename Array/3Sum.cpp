https://leetcode.com/problems/3sum/
#two pointer 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            if(i>0 && nums[i] == nums[i-1]) continue; // to remove duplicates
            int j = i+1, k = n-1;
            while(j<k) {
                if(j>i+1 && nums[j] == nums[j-1]) { // to remove duplicates
                    j++;
                    continue;
                }
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (sum < 0) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        return ans;
    }
};

