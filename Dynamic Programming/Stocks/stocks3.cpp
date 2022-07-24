
class Solution {
public:
    vector<vector<vector<int>>> mem;
    int solve(vector<int>& p, int pos, int t, bool bought) {
        if(pos>=p.size() || t == 0) return 0;
        if(mem[bought][t][pos] != -1) return mem[bought][t][pos];
        
        int res = solve(p, pos+1, t, bought);
        if(bought) {
            res = max(res, solve(p, pos+1, t-1, !bought)+p[pos]);
        }
        else {
            res = max(res, solve(p, pos+1, t, !bought)-p[pos]);
        }
        return mem[bought][t][pos] = res;
    }
    int maxProfit(vector<int>& p) {
        // bought transaction position
        mem.resize(2,vector<vector<int>>(3,vector<int>(p.size(),-1)));
        return solve(p, 0, 2, false);
    }
};


class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp (n+1, vector<vector<int>>(3, vector<int>(2, 0)));
        for(int i = n-1; i>=0; i--) {
            for(int j = 1; j<=2; j++) {
                dp[i][j][1] = max( dp[i+1][j-1][0] + p[i],  dp[i+1][j][1]);
                dp[i][j][0] = max( dp[i+1][j][1] - p[i],  dp[i+1][j][0]);   
            }
        }
        
        return dp[0][2][0];
    }
};


class Solution {
public:

    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> next (3, vector<int>(2, 0)), curr (3, vector<int>(2, 0));
        for(int i = n-1; i>=0; i--) {
            for(int j = 1; j<=2; j++) {
                curr[j][1] = max( next[j-1][0] + p[i], next[j][1]);
                curr[j][0] = max( next[j][1] - p[i],  next[j][0]);   
            }
            next = curr;
        }
        
        return next[2][0];
    }
};




