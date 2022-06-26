// https://leetcode.com/problems/range-sum-query-mutable/solution/

class NumArray {
public:
    vector<int> segmentedTree;
    vector<int> arr;
    int n = 0;
    
    int buildTree(int node, int left, int right) { // O(N)
        if(left == right) {
            segmentedTree[node] = arr[left];
            return segmentedTree[node];
        }
        int mid = (left+right)/2;
        int leftSum = buildTree(2*node, left, mid);
        int rightSum = buildTree(2*node + 1, mid+1, right);
        segmentedTree[node] = leftSum + rightSum;
        return segmentedTree[node];
    }
    
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        segmentedTree.resize(4*n, 0);
        buildTree(1, 0, n-1);
    }
    
    void updateTreeHelper(int idx, int val, int node, int left, int right) { // O(logN)
         if(left == right) {
            arr[idx] = val;
            segmentedTree[node] = val;
            return;
        }
        int mid = (left+right)/2;
        if(left<=idx && idx<=mid)
            updateTreeHelper(idx, val, 2*node, left, mid);
        else
            updateTreeHelper(idx, val, 2*node + 1, mid+1, right);
        
        segmentedTree[node] =  segmentedTree[2*node] + segmentedTree[2*node + 1];
        return;
    }
    
    void update(int idx, int val) {
        updateTreeHelper(idx, val, 1, 0, n-1);
  
    }

    int sumRangeHelper(int rangeStart, int rangeEnd, int node, int left, int right) { // O(logN)
        if(rangeStart>right || rangeEnd<left) return 0;
        else if(left == right) return segmentedTree[node]; 
        else if(rangeStart <= left && right <= rangeEnd) {
            return segmentedTree[node];
        }
        else {
            int mid = (left+right)/2;
            int leftSum = sumRangeHelper(rangeStart, rangeEnd, 2*node, left, mid);
            int rightSum = sumRangeHelper(rangeStart, rangeEnd, 2*node + 1, mid+1, right);
            return leftSum + rightSum;
        }
    }
    
    int sumRange(int rangeStart, int rangeEnd) {
        return sumRangeHelper(rangeStart, rangeEnd, 1, 0, n-1);  
    }
};
