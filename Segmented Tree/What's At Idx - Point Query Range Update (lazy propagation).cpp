// https://www.youtube.com/watch?v=rDvwI6pyyYs&list=PL-Jc9J83PIiFY1445K_x1M_O3j9kr3FII&index=4
// lazy propagation
#include<iostream>
#include<vector>
using namespace std;

void propagate(int node, vector<int> &segmentedTree) {
    
    int left = 2*node;
    int right = 2*node+1;
    segmentedTree[left] += segmentedTree[node];
    segmentedTree[right] += segmentedTree[node];
    segmentedTree[node] = 0;
}

int query(int node, vector<int> arr, vector<int> &segmentedTree, int idx, int start, int end) {
    // do not propagate if at leaf node
    if(start == end) {
        return segmentedTree[node];
    }
    else {
        propagate(node, segmentedTree);
        int mid = (start+end)/2;
        if(start<=idx && idx<=mid) {
            return query(2*node, arr, segmentedTree, idx, start, mid);
        }
        else {
            return query(2*node+1, arr, segmentedTree, idx, mid+1, end);
        }
    }
}

void update(int node, vector<int> arr, vector<int> &segmentedTree, int start, int end, int l, int r, int val) {
    if(r<start || l>end) return ;
    if(start == end) {
        segmentedTree[node] += val;
    }
    else if(l<=start && end<=r) {
        segmentedTree[node] += val;
    }
    else {
        int mid = (start+end)/2;
        update(2*node, arr, segmentedTree, start, mid, l, r, val);
        update(2*node+1, arr, segmentedTree, mid+1, end, l, r, val);
    }
}

void buildTree(int node, vector<int> arr, vector<int> &segmentedTree, int start, int end) {
    if(start == end) {
        segmentedTree[node] = arr[start];
    }
    else {
        int mid = (start+end)/2;
        buildTree(2*node, arr, segmentedTree, start, mid);
        buildTree(2*node+1, arr, segmentedTree, mid+1, end);
        segmentedTree[node] = 0;
    }
}

int main() {
    int n, q;
    cin>>n;
    vector<int> arr(n, 0), segmentedTree(4*n, 0);
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    
    cin>>q;
    buildTree(1, arr, segmentedTree, 0, n-1);
    // for(int i = 0; i<4*n;i++) cout<<segmentedTree[i]<<" ";
    // cout<<endl;
    while(q--) {
        int x;
        cin>>x;
        if(x == 0) {
            int idx;
            cin>>idx;
            cout<<query(1, arr, segmentedTree, idx, 0, n-1)<<endl;
            
        }
        else {
            int l, r, val;
            cin>>l>>r>>val;
            update(1,arr, segmentedTree, 0, n-1, l, r, val);
        }
    //         for(int i = 0; i<4*n;i++) cout<<segmentedTree[i]<<" ";
    // cout<<endl;
    }
}
