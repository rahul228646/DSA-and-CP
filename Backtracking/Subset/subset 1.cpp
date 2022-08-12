// Time : O(N * 2^N) // N is to copy the array
class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int n, int i, vector<int> &temp) {
        ans.push_back(temp);
        for(int j = i; j<n; j++) {
            temp.push_back(nums[j]);
            solve(nums, n, j+1, temp);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        solve(nums, n, 0, temp);
        return ans;
    }
};

// Time : O(k * 2^N)
class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        
        int total = 1<<n; // 2^n
        for(int i = 0; i<total; i++) {
            vector<int> temp;
            for(int j = 0; j<n; j++) {
                if(i&(1<<j)) {
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
