https://leetcode.com/problems/generate-parentheses/submissions/
Time Complexity : O(4^n / n^1/2)
Space Complexity : O(4^n / n^1/2)

class Solution {
public:
    vector<string> ans;
    void solve (string s, int leftNeeded, int moreLeft) {
        if(leftNeeded == 0 && moreLeft == 0) {
            ans.push_back(s);
            return;
        }
        if(leftNeeded>0) {
            solve(s+"(", leftNeeded-1, moreLeft+1);
        }
        if(moreLeft>0)
             solve(s+")", leftNeeded, moreLeft-1);
    }
    vector<string> generateParenthesis(int n) {
        solve("", n, 0);
        return ans;
    }
};
