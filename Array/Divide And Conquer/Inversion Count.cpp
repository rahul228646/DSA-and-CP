https://www.geeksforgeeks.org/counting-inversions/

long long int merge(long long arr[], long long temp[], long long l, long long mid, long long r) {
        long long i = l, j = mid, k = l, countInversion = 0;
        while(i<=mid-1 && j<=r) {
            if(arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            }
            else {
                temp[k++] = arr[j++];
                countInversion += (mid-i);
            }
        }
        while (i <= mid - 1) temp[k++] = arr[i++];
        while (j <= r) temp[k++] = arr[j++];


        for (i = l; i <= r; i++) arr[i] = temp[i];
        return countInversion;
}
    
    long long int mergeSort(long long arr[], long long l, long long r, long long temp[]) {
        long long mid = 0, countInversion = 0;
        if(l<r) {
            mid = (l+r)/2;
            countInversion += mergeSort(arr, l, mid, temp);
            countInversion += mergeSort(arr, mid+1, r, temp);
            countInversion += merge(arr, temp, l, mid+1, r);
        }
        return countInversion;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long temp[N];
        return mergeSort(arr, 0, N-1, temp);
    }

          {5, 4, 3, 2, 1}
              /     \
        {5, 4, 3}    {2, 1}  
          /   \       /  \
     {5, 4}    {3}   {2} {1}
       / \
    {5}  {4}  
              |  merging
              |
{1+2+3+3}        +        {1}  ==> 10
          {1, 2, 3, 4, 5}
              /     \
 {1+2} {3, 4, 5}    {1, 2} {1}  
          /   \       /  \
{1} {4, 5}    {3}   {2}  {1}
       / \
    {5}  {4}  

inversion Cost          --->   2 
merging of {4 5}   {3}  --->  {3, 4, 5}


inversion Cost                 --->   3  3
merging of {3, 4, 5}   {1, 2}  --->  {1, 2, 3, 4, 5}

