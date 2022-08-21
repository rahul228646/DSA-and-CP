// https://leetcode.com/problems/replace-the-substring-for-balanced-string/discuss/409017/JAVA-Sliding-Window-Solution-with-Explanation
// https://leetcode.com/problems/replace-the-substring-for-balanced-string/submissions/
class Solution {
public:
    int balancedString(string s) {
        int n = s.length();
        int m = n/4;
        unordered_map<char, int> extraCharacters;
        for(auto i : s) {
            extraCharacters[i]++;
        }
        bool flag = true;
        for(auto i : extraCharacters) {
            if(i.second != m) {
                flag = false;
            }
            extraCharacters[i.first] = max(0, i.second-m);
            
        }
        if(flag) return 0;
        int l = 0, ans = n;
        for(int i = 0; i<n; i++) {
            extraCharacters[s[i]]--;
            while(extraCharacters['Q']<=0 && 
                  extraCharacters['R']<=0 && 
                  extraCharacters['E']<=0 && 
                  extraCharacters['W']<=0) {
                // cout<<ans<<endl;
                ans = min(ans, i-l+1);
                extraCharacters[s[l]]++;
                l++;
            }
            
        }

        return ans;
    }
};

// "WWEQERQWQWWRWWERQWEQ"
// w = 8, q = 5, e = 4, r = 3
