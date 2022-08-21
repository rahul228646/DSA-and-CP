
class Solution {
public:
   int minSwaps(int arr[], int n) {
    
    // Complete the function
    int ones = 0, ans = INT_MAX;
    for(int i = 0; i<n; i++) if(arr[i] == 1) ones++;
    if(ones==0) return -1;
    for(int j = 0, i = 0, cnt = 0; j<n; i++) {
        while(j-i<ones) {
            cnt += arr[j++];
        }
        ans = min(ans, ones-cnt);
        cnt -= arr[i];
    }
    return ans;
}
};
