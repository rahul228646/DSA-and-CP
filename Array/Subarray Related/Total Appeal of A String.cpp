// https://leetcode.com/contest/weekly-contest-291/problems/total-appeal-of-a-string/
class Solution {
public:
    long long appealSum(string s) {
        
        int n = s.size();
        long long int dp[n];
        dp[0] = 1;
        
        vector<int> last_occ(26, -1);
        
        last_occ[s[0] - 'a'] = 0;
        
        for(int i=1;i<n;i++){
            dp[i] = dp[i-1] + i*1ll - last_occ[s[i] - 'a']*1ll;
            last_occ[s[i] - 'a'] = i;
        }
        
        long long int ans = 0;
        
        for(int i=0;i<n;i++) ans += dp[i];
        return ans;
        
    }
};

                            0    1     2        3        4
                            a    b     b        c        a
                       dp   1    3     4        8       12
        
 substr                     a  a|b  ab|b    abb|c   abbc|a
 ending with ith                 b   b|b     bb|c    bbc|a
 chharacter                    1+2     b      b|c     bc|a
                                     3+1        c      c|a
                                     (i-last  4+4        a
                                     occurance         8+4
                                     of ith cahr)
                                
                                
                      ans - 1+2+4+8+12 = 28
