Given an array of non-negative integers arr, you are initially positioned at start index of the array. 
When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.
Notice that you can not jump outside of the array at any time.
  
// time : O(n) space : O(n)   
class Solution {
public:

    unordered_map<int, bool> visited;
    bool canReach(vector<int>& arr, int start) {
        if(start < 0 || start >= arr.size()) return false;
        if(arr[start] == 0) return true;
        if(visited.find(start) != visited.end()) return false;
        visited[start] = true;
        return canReach(arr, start-arr[start]) || canReach(arr, start+arr[start]);
    }
    
};

// if all no.s are positive 
  
class Solution {
public:
    bool canReach(vector<int>& A, int cur) {
        if(cur < 0 || cur >= size(A) || A[cur] < 0) return false;                  
        A[cur] *= -1;       // mark as visited by making -ve
        return !A[cur] || canReach(A, cur + A[cur]) || canReach(A, cur - A[cur]);  // return true if A[cur] == 0 or recurse for both possible jumps
    }
};
