
class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int n, int i, vector<int> &temp) {
        ans.push_back(temp);
        for(int j = i; j<n; j++) {
            if(j>i && nums[j]==nums[j-1]) continue; // just add this line in subset1  and also sort the array before hand
            temp.push_back(nums[j]);
            solve(nums, n, j+1, temp);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> temp;
        solve(nums, n, 0, temp);
        return ans;
    }
};
