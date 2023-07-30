https://leetcode.com/problems/maximize-the-confusion-of-an-exam/


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
    int maxConsecutiveAnswers(string s, int k) {
        int t = 0, f = 0, n = s.length(), i = 0, j = 0, l = 0, ans = 0;
        for(;j<n;j++) {
            t += s[j] == 'T';
            while(t>k) {
               t -= s[i++] == 'T'; 
            }
            ans = max(ans, j-i+1);
            f += s[j] == 'F';
            while(f>k) {
               f -= s[l++] == 'F'; 
            }
            ans = max(ans, j-l+1);
        }
        return ans;
    }
};

or 


class Solution {
public:
    int solve(string s, int k, char c) {
        int x = 0, n = s.length(), i = 0, j = 0, ans = 0;
        for(;j<n;j++) {
            x += s[j] == c;
            while(t>k) {
               t -= s[i++] == c; 
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
    int maxConsecutiveAnswers(string s, int k) {
        
        return max( solve(s, k, 'T'), solve(s, k, 'F'));
    }
    
    
};
