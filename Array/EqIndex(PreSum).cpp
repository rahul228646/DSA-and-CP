    
https://www.geeksforgeeks.org/equilibrium-index-of-an-array/

int equilibriumPoint(long long a[], int n) {
        long long sumPre = 0, sum = 0;
        for(int i = 0; i<n; i++) sumPre += a[i];
        for(int i = 0; i<n; i++) {
            sumPre -= a[i];
            if(sum == sumPre) {
                return i+1;
            }
            sum += a[i];
        }
        return -1;
}
