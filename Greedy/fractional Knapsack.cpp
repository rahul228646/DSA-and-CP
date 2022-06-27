class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(Item& a, Item& b) {
        return ((double)a.value/(double)a.weight > (double)b.value/(double)b.weight);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr+n, cmp);
        double ans = 0;
        for(int i = 0; i<n; i++) {
            if(arr[i].weight <= W){
                W -= arr[i].weight;
                ans += arr[i].value;
            }
            else if (W==0) {
                break;
            }
            else {
               ans += ((double)arr[i].value/(double)arr[i].weight)*((double)W);
               W = 0;
            }
        }
        return ans;
    }
        
};
