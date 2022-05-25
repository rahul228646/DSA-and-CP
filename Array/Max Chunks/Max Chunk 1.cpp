https://leetcode.com/problems/max-chunks-to-make-sorted/submissions/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int prev = 0, count = 0, sum = 0, n = arr.size();
        for(int i = 0; i<n; i++) {
            sum += arr[i];
            int nSum = i*(i+1)/2;
            // cout<<i<<" "<<sum<<" "<<nSum<<" "<<prev<<endl; 
            if(sum == (nSum - prev)) {
                prev = nSum;
                sum = 0;
                count++;
            }
        }
        if(!count) return 1;
        return count;
    }
};

// since array elemnets are from 0 to n-1 , there at at each index we cal. the sum of ith numbers if this is equal to sum of numbers upto this point , 
// then this makes 1 chunk 
// |  chunk  1   | chunk 2 |  chunk 3 |
// 0             i         j          n

// sum of chunk 1 == sum of ith numbers using formula
// sum of chunk 2 == sum of jth numbers - sum of chunk 2;
  
  
