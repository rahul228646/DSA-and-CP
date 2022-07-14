// https://leetcode.com/problems/get-equal-substrings-within-budget/
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0, j = 0, temp = maxCost, ans = 0;
        int n = s.length();
        while(j<n) {
            
            if(s[j] == t[j]) {
                ans = max(ans, j-i+1);
                j++;
            }
            else {
                int change = abs(s[j]-t[j]);
                while(change>temp && i<j) {
                    temp += abs(s[i]-t[i]);
                    i++;
                }
                if(change <= temp) {
                    temp-=change;
                    ans = max(ans, j-i+1);
                    j++;
                }
                else {
                    j++;
                    i = j;
                }
            }
        }
        return ans;
    }
};

// or

int equalSubstring(string s, string t, int maxCost) {
  auto i = 0, j = 0;
  while (i < s.size()) {
    maxCost -= abs(s[i] - t[i++]);
    if (maxCost < 0) maxCost += abs(s[j] - t[j++]);
  }
  return i - j;
}
