https://leetcode.com/problems/minimum-cost-to-cut-a-stick/submissions/

class Solution {
public:
    int solve(vector<int>& arr, int i, int j, vector<vector<int>> &dp) {
        if(i+1>=j) return 0;
        int mn = INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = i+1; k<j; k++) {
            int cost = arr[j]-arr[i]+solve(arr, i, k, dp)+solve(arr, k, j, dp);
            mn = min(mn, cost);
        }
        return dp[i][j] = mn;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size()+1, vector<int>(cuts.size()+1, -1));
        return solve(cuts, 0, cuts.size()-1, dp);
    }
};


class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size()+1, vector<int>(cuts.size()+1, 0));
        for(int i = cuts.size()-1; i>=0; i--) {
            for(int j = i+2; j<cuts.size(); j++) {
                 int mn = INT_MAX;
                for(int k = i+1; k<j; k++) {
                     int cost = cuts[j]-cuts[i]+dp[i][k]+dp[k][j];
                     mn = min(mn, cost);
                }
                dp[i][j] = mn;
            }
        }
        return dp[0][cuts.size()-1];
    }
};
