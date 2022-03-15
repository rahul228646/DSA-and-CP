// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        stack<int>st, t_st;
        for(int i = 0; i<s.length(); i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else if(s[i] == ')' && !st.empty() && s[st.top()] == '('){
                st.pop();
            }
            else if(s[i] == ')') {
                st.push(i);
            }
        }

        // this step is because we need to reverse the stack
        while(!st.empty()) {
            t_st.push(st.top());
            st.pop();
        }
        // cout<<t_st.size()<<endl;
        for(int i = 0; i<s.length(); i++) {
            if(!t_st.empty() && i == t_st.top()) t_st.pop();
            else ans += (s[i]);
        }
        return ans;
    }
};
// l e e ( t ( c ) o )  d e  )
// 0 1 2 3 4 5 6 7 8 9 10 11 12    
  
// stack -->
// 3 5 7    
