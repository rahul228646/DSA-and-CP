class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n, -1);
        for(int i = n-1; i>=0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if(!st.empty()) ans[i] = nums[st.top()];
            st.push(i);
        }
        
        for(int i = n-1; i>=0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                    st.pop();
                }
                if(!st.empty()) ans[i] = nums[st.top()];
                st.push(i);
            
        }
        return ans;
    }
};
