https://leetcode.com/contest/biweekly-contest-67/problems/find-good-days-to-rob-the-bank/
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& s, int time) {
        int n = s.size();
        vector<int> ans, prefix(n, 0), suffix(n, 0);
     
        for(int i = 1; i<n; i++) {
            if(s[i-1] >= s[i]) {
                prefix[i] = 1+prefix[i-1];
            }
        }
        
        for(int i = n-2; i>=0; i--) {
            if(s[i] <= s[i+1]) {
                suffix[i] = 1+suffix[i+1];
            }
        }
        
        for(int i = time; i<n-time; i++) {
            if(prefix[i]>=time && suffix[i]>=time) ans.push_back(i);
        }
        return ans;
    }
};
