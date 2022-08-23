// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
class Solution {
public:
    //from left-bottom or right-top, count how many numbers are less equal than mid
    int solve(vector<vector<int>>& matrix, int mid){
        int count = 0, n = matrix.size(), i = n-1, j = 0;
        while(i >= 0 && j < n){
            if(matrix[i][j] > mid) i--;
            else{
                count += (i+1); // counting no of elements int the jth colum
                j++;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), i = matrix[0][0], j = matrix[n-1][n-1], ans = 0;
        while(i <= j){
            int mid = (i + j)/2;

            int posi = solve(matrix, mid);

            if(posi < k) {
                i = mid+1;
            }
            else {
                ans = mid;
                j = mid-1;
            }
        }
        return ans;
    }  
};
