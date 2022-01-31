// similar to LIS - longest increasing subsequence

// time : O(n^2) space : O(n)

 vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), overAllMax = 0, overAllMaxIndex = 0;
        vector<int> dp(n, 0), find(n, 0), ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++) {
            int max = 0;
            find[i] = i;
            for(int j = 0; j<i; j++) {
                if(nums[i] % nums[j] == 0) { // (nums[j] < nums[i]) for lis
                    if(dp[j] > max) {
                        max = dp[j];
                        find[i] = j; 
                    }
                }
            }
            dp[i] = max+1;
            if(dp[i]>overAllMax) {
                overAllMax = dp[i];
                overAllMaxIndex = i;
            }
        }
//         this part is similar to find as in union and find
        int i = overAllMaxIndex;
        while(find[i] != i) {
            ans.push_back(nums[i]);
            i = find[i];
        }
        ans.push_back(nums[i]);
   
        return ans;
    }
