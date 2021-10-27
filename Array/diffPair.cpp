
https://www.geeksforgeeks.org/find-a-pair-with-the-given-difference/
// time - o(nlogn)
// space - 1

bool findPair(int arr[], int size, int n){
    //code
    sort(arr, arr+size);
    int i = 0, j = 1;
    while(j<size) {
        int diff = arr[j]-arr[i];
        if(diff == n) {
            return true;
        }
        if(diff<n) {
            j++;
        }
        else {
            i++;
        }
    }
    return false;
}
