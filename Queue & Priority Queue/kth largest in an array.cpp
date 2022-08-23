// Time : O(N + LogK)
int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end()); // O(N) build heap
	    for(int itr = 1; itr < k; itr++) pq.pop();
	    return pq.top();
}

// Time : O(N * LogK)
int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto i : nums) {
            if(pq.size()==k) {
                if(pq.top()<i) {
                    pq.pop();
                    pq.push(i);
                }
            }
            else {
                pq.push(i);
            }
        }
        return pq.top();
    }
