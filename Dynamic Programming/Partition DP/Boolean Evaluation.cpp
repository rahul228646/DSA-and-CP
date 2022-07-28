
   unordered_map<string, int> m;
   int solve (string s, int i, int j, bool isTrue) {
       if(i>j)
           return 0;
       if(i==j) {
           if(isTrue) return s[i] == 'T';
           else return s[i] == 'F';
             
       }
       string temp = to_string(i)+" "+ to_string(j)+" "+ to_string(isTrue);
       if(m.find(temp) != m.end())
           return m[temp];

       int ans = 0;
       for (int k = i+1; k<=j-1; k+=2) {
           int leftT = solve(s, i,k-1,true);
           int leftF = solve(s, i,k-1,false);
           int rightT = solve(s,k+1,j,true);
           int rightF = solve(s, k+1,j, false);
           if(s[k] == '&') {
               ans += (isTrue) ? (leftT*rightT) : (leftF*rightT + leftT*rightF + leftF*rightF);
           }
           if(s[k] == '|') {
               ans += (isTrue) ?  (leftF*rightT + leftT*rightF + leftT*rightT) : (leftF*rightF);
           }
           if(s[k] == '^') {
               ans += (isTrue) ?  (leftF*rightT + leftT*rightF) : (leftT*rightT + + leftF*rightF);
           }
       }
       return m[temp] = ans;
   }
   int evaluateExp(string & s) {
       m.clear();
       return solve(s, 0, s.length()-1, true);
   }

//





#define ll long long int
ll mod=1000000007;
int evaluateExp(string & exp) {
    int n=exp.length();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,0)));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            if(i==j)
            {
                dp[i][j][0]=(exp[i]=='F');
                dp[i][j][1]=(exp[i]=='T');
            }
            else 
            {
                ll ways=0;
                for(ll ind=i+1;ind<=j-1;ind+=2)
                {
                    ll lt=dp[i][ind-1][1]%mod;
                    ll rt=dp[ind+1][j][1]%mod;
                    ll lf=dp[i][ind-1][0]%mod;
                    ll rf=dp[ind+1][j][0]%mod;
                    if(exp[ind]=='&')
                    {
                        dp[i][j][0]=(dp[i][j][0]+(lt*rf+lf*rt+lf*rf))%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lt*rt))%mod;
                    }
                    else if(exp[ind]=='|')
                    {
                        dp[i][j][0]=(dp[i][j][0]+(lf*rf))%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lt*rf+lf*rt+lt*rt))%mod;
                    }
                    else
                    {
                        dp[i][j][0]=(dp[i][j][0]+(lt*rt+lf*rf))%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lt*rf+lf*rt))%mod;
                    }
                }
            }
        }
    }
    return dp[0][n-1][1];
}
