class Solution {
public:
    int dp[100001];
    int solve(vector<int>& s, int n, int i) {
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i]; 
        int sum = 0;
        int ans = INT_MIN;
        for(int j = 0; j<3; j++) {
            if(i+j<n)
                sum += s[i+j];
            ans = max(ans, sum - solve(s, n, j+i+1));
            dp[i] = ans;
        }
        return dp[i] = ans;
    }
    
    string stoneGameIII(vector<int>& s) {
        int sum = 0;
        // for(auto i : s) sum+=s;
        memset(dp, -1, sizeof(dp));
        int diff = solve(s, s.size(), 0);
        if(diff < 0) return "Bob";
        else if (diff == 0) return "Tie";
        else return "Alice";
    }
};



class Solution {
public:
    // dp[i] denotes the maximum score if alice takes the ith stone
    int dp[50005];
    
    int solve(int i, vector<int>&a){
        int n=a.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int alice=0,ans=INT_MIN;
        
        // alice can take upto 3 stones
        
        for(int k=i;k<min(n,i+3); k++){
            alice+=a[k];
            
            // after alice takes bob will take 1,2,3 and leave the minimum for alice
            ans=max(ans, alice+min({solve(k+2,a), solve(k+3,a) , solve(k+4,a)}));
        }
        return dp[i]=ans;
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        
        memset(dp,-1,sizeof dp);
        int aliceScore=solve(0,stoneValue);
        
        int bobScore=accumulate(stoneValue.begin(),stoneValue.end(),0)-aliceScore;
        if(aliceScore>bobScore) return "Alice";
        else if(aliceScore==bobScore) return "Tie";
        return "Bob";
    }
};
