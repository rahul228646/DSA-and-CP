class Solution {
public:
    
    vector<vector<string>> ans;
    bool isPalindrome(string s, int i, int j) {
        while(i<=j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string s, int idx, int n, vector<string> &temp) {
        if(idx == n) {
            ans.push_back(temp);
            return;
        }
        for(int i = idx; i<n; i++) {
            if(isPalindrome(s,idx,i)) {
                temp.push_back(s.substr(idx, i-idx+1));
                solve(s, i+1, n, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string> temp;
        solve(s, 0, n, temp);
        return ans;
    }
};
