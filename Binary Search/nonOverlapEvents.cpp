
// https://leetcode.com/problems/two-best-non-overlapping-events/
// time : O(nlogn) space : O(n) - space for array

class Solution {
public:
    int findIndex (vector<vector<int>>& e, int end) {
        int m = 0, l = 0, h = e.size();
        while(l<h) {
            m = (l+h)/2;
            if(e[m][0]>end) h = m;
            else l = m+1;
        }
        return l;
    }
    int maxTwoEvents(vector<vector<int>>& e) {
        int maxVal = 0, n = e.size();
      
//       sort the array in increasing order of start time
        int maxVal = 0, n = e.size();
        sort(e.begin(), e.end());
        vector<int> arr(n, 0);
      
//       store maximum val of an event from the back i.e. max value of an event that starts at a later time
        for(int i = n-1; i>=0; i--) {
            maxVal = max(e[i][2], maxVal);
            arr[i] = maxVal;
        }
      
        maxVal = 0;
        for(int i = 0; i<n; i++) {
//           find the index of an an event that just starts after ith event has finished
            int x = findIndex(e, e[i][1]);
//           if an index was found then add arr[index] to the current val
            if(x<n) {
                maxVal = max(maxVal, e[i][2]+arr[x]);
            }
            else {
                maxVal = max(maxVal, e[i][2]);
            }
        }
        
        return maxVal;
    }
};

