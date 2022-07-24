

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), overAllMax = 0, overAllMaxIndex = 0;
        vector<int> dp(n, 0), find(n, 0), ans;
        sort(nums.begin(), nums.end());
      
        for(int i = 0; i<n; i++) {
            find[i] = i;
            for(int j = 0; j<i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(1+dp[j] > dp) {
                        dp = 1+dp[j];
                        find[i] = j; 
                    }
                }
            }

            if(dp[i]>overAllMax) {
                overAllMax = dp[i];
                overAllMaxIndex = i;
            }
        }
        
        int i = overAllMaxIndex;
        // cout<<find[i]<<endl;
        while(find[i] != i) {
            ans.push_back(nums[i]);
            i = find[i];
        }
        ans.push_back(nums[i]);
        return ans;
    }
};
