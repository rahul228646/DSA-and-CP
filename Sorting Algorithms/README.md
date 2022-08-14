# Sorting Algorithms


<img width="635" alt="Screenshot 2022-08-14 at 3 39 28 PM" src="https://user-images.githubusercontent.com/56363090/184532160-4baad069-987b-4bbc-8891-4c84df6a9f5e.png">

## Bubble Sort

      void bubbleSort(int arr[], int n) {
        int i, j;
        for (i = 0; i < n - 1; i++)

            // Last i elements are already 
            // in place

            for (j = 0; j < n - i - 1; j++)
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
      }
    
    
    For the Worst case: (array is sorted in decreasing order)

    Total number of swaps = Total number of comparison
    Total number of comparison (Worst case) = n(n-1)/2
    Total number of swaps (Worst case) = n(n-1)/2
    
## Selection Sort
  
