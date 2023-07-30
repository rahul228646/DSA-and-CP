https://leetcode.com/problems/longest-repeating-character-replacement/


class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {
        unordered_map<int, int> mp;
        int i = 0 , j = 0, n = a.length(), ans = 0, mxFreq = 0;
        for(int j = 0; j<n; j++) {
            mp[a[j]]++;
            mxFreq = max(mp[a[j]], mxFreq);
            while(j-i+1 - mxFreq > k && i<j) {
                mp[a[i++]]--;
                // mxFreq = 0;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};


class Solution {
public:
    int solve(string s, int k, char c) {
        int x = 0, n = s.length(), i = 0, j = 0, ans = 0;
        for(;j<n;j++) {
            x += s[j] != c;
            while(x>k) {
                x -= s[i++] != c;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
    int characterReplacement(string s, int k) {
        int ans = 0;
        for(int i = 0; i<26; i++) {
            ans = max(ans, solve(s, k, 'A'+i));
        }
        return ans;
    }
};
