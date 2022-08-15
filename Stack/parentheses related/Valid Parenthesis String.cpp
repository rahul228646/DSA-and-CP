// https://leetcode.com/problems/valid-parenthesis-string/
// Time : O(3^N) 
class Solution {
public:
    bool solve(string s, int idx, int n, int open) {
        if(idx == n) return open == 0;
        if(s[idx] == '(') {
            return solve(s, idx+1, n, open+1);
        }
        else if(s[idx] == ')') {
            if(open == 0) return false;
            return solve(s, idx+1, n, open-1);
        }
        else {
            // * -> ) || empty || (
            return solve(s, idx+1, n, open-1) || solve(s, idx+1, n, open) || solve(s, idx+1, n, open+1);
        }
    }
    bool checkValidString(string s) {
        return solve(s, 0, s.length(), 0);
    }
};

// Time : O(N^3) Space : O(N^2)
class Solution {
public:
    bool solve(string s, int idx, int n, int open, vector<vector<int>> &dp) {
        if(idx == n) return open == 0;
        if(dp[idx][open] != -1) {
            return dp[idx][open];
        }
        if(s[idx] == '(') {
            return dp[idx][open] = solve(s, idx+1, n, open+1, dp);
        }
        else if(s[idx] == ')') {
            if(open == 0) return dp[idx][open] = false;
            return dp[idx][open] = solve(s, idx+1, n, open-1, dp);
        }
        else {
            // * -> ) || empty || (
            return dp[idx][open] = (open != 0 && solve(s, idx+1, n, open-1, dp)) || solve(s, idx+1, n, open, dp) || solve(s, idx+1, n, open+1, dp);
        }
    }
    bool checkValidString(string s) {
        
        vector<vector<int>> dp(s.length()+1, vector<int>(1000, -1));
        return solve(s, 0, s.length(), 0, dp);
    }
};

// if we have string '(***)', then as we parse each symbol, the set of possible values for the balance is 
// [1] for '('; 
// [0, 1, 2] for '(*'; 
// [0, 1, 2, 3] for '(**'; 
// [0, 1, 2, 3, 4] for '(***'
// [0, 1, 2, 3] for '(***)'.
    
// Let lo, hi respectively be the smallest and largest possible number of open left brackets after processing the current character in the string.

// Time : O(N)

class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0, hi = 0;
        for(auto i : s) {
            lo += (i == '(') ? 1 : -1;
            hi += (i != ')') ? 1 : -1;
            if(hi<0) break;
            lo = max(lo, 0);
        }
        return lo == 0;
    }
};

// or
    
class Solution {
public:
    vector<vector<int>> dp;
    bool checkValidString(string s) {
        int leftOpenMin = 0, leftOpenMax = 0, n= s.size();
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                leftOpenMin += 1;
                leftOpenMax += 1;
            }
            
            else if(s[i] == ')'){
                leftOpenMin -= 1;
                leftOpenMax -= 1;
            }
            
            else if(s[i] == '*'){
                //* is )
                leftOpenMin -= 1;
                
                //* is (
                leftOpenMax += 1;
            }
            
            if(leftOpenMax < 0){
                //Case like ))()
                return false;
            }
            
            if(leftOpenMin < 0) {
                //Minimum left open can't be lesser than 0, so reset it to 0.
                leftOpenMin = 0;
            }
        }
        return leftOpenMin == 0;
    }
};
