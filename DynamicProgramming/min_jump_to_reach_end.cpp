
// Time : O(n) Space : O(1)
class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if (n <= 1)
            return 0;
        if (arr[0] == 0)
            return -1;
        int maxReach = arr[0]; // max Reachable index
        int jump = 1, 
        int step = arr[0];
        for(int i = 1; i<n; i++) {
            if(i == n-1) return jump;
            maxReach = max(maxReach, i+arr[i]);
            step--;
            if(step == 0) {
                jump++;
                if(i>=maxReach) return -1;
                step = maxReach - i;

            }
        }
        return -1;
        
    }
};


                                          
