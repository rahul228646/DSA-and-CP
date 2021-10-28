
// https://users.monash.edu/~lloyd/tildeAlgDS/Sort/Flag/
// https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

// three sectionas low mid high
// low - 0 mid - 1 high 2
// we need to shrink mid

    void sort012(int a[], int n)
    {
        int low = 0, mid = 0, high = n-1;
        while(mid<=high) {
            if(a[mid] == 0) {
                swap(a[low], a[mid]);
                low++;
                mid++;
            }
            else if (a[mid] == 1) {
                mid++;
            }
            else {
                swap(a[mid], a[high]);
                high--;
            }
        }
    }
