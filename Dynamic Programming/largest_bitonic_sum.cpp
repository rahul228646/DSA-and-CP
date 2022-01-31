
int maxSumBS(int arr[] , int n )
{
    vector<int> lisSum(n, 0), ldsSum(n, 0);
    for(int i = 0; i<n; i++) {
        int mx = INT_MIN;
        for(int j = 0; j<i; j++) {
            if(arr[i]>arr[j]) {
                mx = max(mx, lisSum[j]);
            }
        }
        lisSum[i] = mx + arr[i];
    }
    
    for(int i = n-1; i>=0; i--) {
        int mx = INT_MIN;
        for(int j = n-1; j>i; j--) {
            if(arr[i]>arr[j]) {
                mx = max(mx, ldsSum[j]);
            }
        }
        ldsSum[i] = mx + arr[i];
    }
    int mx = lisSum[0]+ldsSum[0]-arr[0]; 
    for(int i = 1; i<n; i++) {
        mx = max(lisSum[i]+ldsSum[i]-arr[i], mx); 
    }
    return mx;
}
