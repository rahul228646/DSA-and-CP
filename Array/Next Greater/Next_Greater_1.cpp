// https://leetcode.com/problems/next-greater-element-i/submissions/
// Time : O(n+m) Space : O(n)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
     
        unordered_map<int, int> m;
        vector<int> ans;
        stack<int> st;
        for(auto i : nums2) {
            while(!st.empty() && st.top() < i) {
                m[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        for(auto i : nums1) (m.find(i) != m.end()) ? ans.push_back(m[i]) : ans.push_back(-1);
        return ans;
    }
};
