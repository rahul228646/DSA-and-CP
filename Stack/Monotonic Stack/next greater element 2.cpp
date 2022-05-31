class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        vector<int> ans(arr.size(), -1);
        stack<int> st; // decreasing stack;
        st.push(0);
        for(int i = 1; i<arr.size(); i++) {
            while(st.size() && arr[st.top()] < arr[i]) {
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        for(int i = 0; i<arr.size(); i++) {
            while(st.size() && arr[st.top()] < arr[i]) {
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
