
// https://leetcode.com/problems/max-chunks-to-make-sorted-ii/submissions/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;
        for(int i = 0; i<arr.size(); i++) {
            int num = arr[i];
            while(!st.empty() && st.top()>arr[i]) {
                num = max(st.top(), num); // trying to find the last no of the sorted chunk
                st.pop();
            }
            st.push(num);
        }
        return st.size();
    }
};

// 1 0 3 2 4
    
// st          - 1 1 [1 3] [1 3] [1 3 4]
// st.size()   - 1 1  2     2     3
// num         - 1 1  3     3     4 
