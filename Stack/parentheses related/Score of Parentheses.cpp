https://leetcode.com/problems/score-of-parentheses/discuss/1856519/JavaC%2B%2B-Visually-Explained!!

class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        stack<int> st;
        int score = 0;
        for(int i = 0; i<n; i++) {
            if(s[i] == '(') {
                st.push(score);
                score = 0;
            }
            else {
                score = st.top() + max(2*score , 1);
                st.pop();
            }
        }
        return score;
    }
};

class Solution {
public:
  int scoreOfParentheses(string s) {
    int mult = 1;
    int score = 0;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == '(') {
            if (s[i+1] == '(') {
                mult *= 2;
            } else {
                score += mult;
                i++;
            } 
        } else {
            mult = mult/2;
        }
    }
    return score;
}
};
