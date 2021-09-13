class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int arr[])
    {
       // your code here
    int lis[n];
    int oMax = 0;

    for (int i = 0; i < n; i++) {
        int mx = 0;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j])
                mx = max(mx, lis[j]);
        lis[i] = mx + 1;
        oMax = max(dp[i], oMax);
    }
 
    return oMax;
    }
};
