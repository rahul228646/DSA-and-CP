
https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:

int minAddToMakeValid(string s) {
    int count = 0;
    stack<char> st;
    for (auto i : s) {
        if(i=='(') 
            st.push(i);
        else {
            if(!st.empty()) {
                if (st.top() == '(') {
                    st.pop();
                }
            }
            else {
             count++;   
            }
        }
    }

    return count + st.size();
}
};

