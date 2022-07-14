// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int l=0,r=0,csum=0,ans=INT_MAX;
        vector<int> dp(arr.size(),INT_MAX);
        for(;r<arr.size();r++){
            csum+=arr[r];
            while(csum>target)
                csum-=arr[l++];
            if(csum==target){
                dp[r]=r-l+1;
                if(l-1>=0 && dp[l-1]!=INT_MAX)
                    ans=min(ans,dp[r]+dp[l-1]);
            }
            if(r-1>=0)
                dp[r]=min(dp[r-1],dp[r]);
            // cout<<l<<" "<<r<<" "<<dp[r]<<endl;
        }
        
        return ans==INT_MAX?-1:ans;
    }
};
