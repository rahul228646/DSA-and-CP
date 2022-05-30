// https://leetcode.com/problems/daily-temperatures/submissions/

// time : O(n) - there will never be a case where we will have to pop all n elements space : log(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> st; // decreasing stack
        int n = t.size();
        vector<int> ans (n, 0);
        st.push(0);
        for(int i = 1; i<n; i++) {
            while(st.size() && t[st.top()]<t[i]) {
                ans[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
