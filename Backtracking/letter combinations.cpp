https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/
class Solution {
public:
    vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    void solver(string digits, int idx, string current) {
        if(idx == digits.length()) {
            result.push_back(current);
            return;
        }
        string s = v[digits[idx]-'0'];
        for(int i = 0; i<s.length(); i++) {
            current.push_back(s[i]);
            solver(digits,idx+1,current);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        solver(digits, 0, "");
        return result;
    }
};
