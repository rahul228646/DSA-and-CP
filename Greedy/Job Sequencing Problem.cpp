https://www.youtube.com/watch?v=LjPx4wQaRIs&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=48

// Time : O(NlogN) + O(N*M) Space : O(M) where M jobdeadline vector size

class Solution 
{
    public:
    static bool cmp(Job &a, Job &b) {
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n){ 
        // your code here
        sort(arr, arr+n, cmp);
        vector<int> jobdeadline(101, -1);
        int profit = 0, count = 0;
        for(int i = 0; i<n; i++) {
            int x = arr[i].dead;
            while(jobdeadline[x] != -1 && x>1) {
                x--;
            }
            if(jobdeadline[x] == -1) {
                jobdeadline[x] = arr[i].id;
                profit += arr[i].profit;
                count++;
            }
        }
        return {count, profit};
    }
};
