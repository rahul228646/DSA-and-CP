https://leetcode.com/problems/letter-case-permutation/submissions/
time: O(2^n)
class Solution {
public:

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        if(s.length() == 0) {
            ans.push_back("");
            return ans;
        }
        vector<string> temp = letterCasePermutation(s.substr(1));
        for(auto p : temp) {
            if(isdigit(s[0])) {
                ans.push_back(s[0]+p);
            }
            else {
                char c = toupper(s[0]);
                ans.push_back(c + p);
                c = tolower(s[0]);
                ans.push_back(c + p);
            }
        }
        return ans;
    }
};
