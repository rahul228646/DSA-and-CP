
https://www.geeksforgeeks.org/find-subarray-with-given-sum/#

    vector<int> subarraySum(int arr[], int n, long long s)
    {
        long long sum = arr[0];
        vector<int> ans;
        int beg = 0;
        for(int i = 1; i<=n; i++) {
            while(sum > s && beg<i-1) {
                sum = sum - arr[beg];
                beg++;
            }
            if(sum == s) {
                ans.push_back(beg+1);
                ans.push_back(i);
                return ans;
            }
            if (i < n)
                sum += arr[i];
        
            
        }
        if(ans.size() == 0) {
            ans.push_back(-1);
        }
        return ans;
    }
