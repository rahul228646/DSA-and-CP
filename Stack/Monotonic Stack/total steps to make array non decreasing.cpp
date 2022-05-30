// https://leetcode.com/contest/weekly-contest-295/problems/steps-to-make-array-non-decreasing/
// https://www.youtube.com/watch?v=NQGduRE1Crk

class Solution {
public:
    using pr = pair<int, int>;
    int totalSteps(vector<int>& arr) {
        stack<pr> st;
        int n = arr.size(), ans = 0;
        st.push({arr[n-1], 0}); // element and no of elements deleted on its right
        for(int i = n-2; i>=0; i--) {
            int count = 0;
            while(!st.empty() && arr[i] > st.top().first) {
                count = max(count+1, st.top().second);
                st.pop();
            }
            ans = max(ans, count);
            st.push({arr[i], count});
        }
        return ans;
    }
};


eg - > 
  
  10 1 2 5 6 1 2 3
  
  iterating from back -
  
                                     {1, 0} 
         {1, 0}               {2, 0} {2, 0} 
         {2, 0}        {5, 0} {5, 0} {5, 0} 
 {3, 0}  {3, 0} {6, 3} {6, 3} {6, 3} {6, 3} {10, 4}

  
  
