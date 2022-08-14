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
    
## Insertion Sort
  
      void insertionSort(int arr[], int n) { 
          int i, key, j; 
          for (i = 1; i < n; i++)
          { 
              key = arr[i]; 
              j = i - 1; 

              // Move elements of arr[0..i-1],  
              // that are greater than key, to one 
              // position ahead of their 
              // current position
              while (j >= 0 && arr[j] > key)
              { 
                  arr[j + 1] = arr[j]; 
                  j = j - 1; 
              } 
              arr[j + 1] = key; 
          } 
      } 
      
      Insertion sort takes maximum time to sort if elements are sorted in reverse order. 
      And it takes minimum time (Order of n) when elements are already sorted.
      
      insertion sort is a stable sorting algorithm.
      
## Selection Sort


      void selectionSort(int arr[], int n) {
          int i, j, min_idx;

          // One by one move boundary of
          // unsorted subarray
          for (i = 0; i < n-1; i++)
          {

              // Find the minimum element in
              // unsorted array
              min_idx = i;
              for (j = i+1; j < n; j++)
              if (arr[j] < arr[min_idx])
                  min_idx = j;

              // Swap the found minimum element
              // with the first element
              if(min_idx!=i)
                  swap(&arr[min_idx], &arr[i]);
          }
      }
      
## Merge Sort

      class Solution {
      public:
          vector<int> merge(vector<int>& a, vector<int>& b) {
              int i = 0,j = 0;
              vector<int> res;
              while(i<a.size() && j<b.size()) {
                  if(a[i]<=b[j]) {
                      res.push_back(a[i]);
                      i++;
                  }
                  else {
                      res.push_back(b[j]);
                      j++;
                  }
              } 
              if(i<a.size()) for(;i<a.size();i++) res.push_back(a[i]);
              if(j<b.size()) for(;j<b.size();j++) res.push_back(b[j]);
              return res;
          }
          vector<int> sortArray(vector<int>& arr) {
              if(arr.size()<=1) return arr;
              int mid = (arr.size()/2);
              vector<int> v (arr.begin(), arr.begin()+mid);
              auto a = sortArray(v);
              vector<int> t (arr.begin()+mid, arr.end());
              auto b = sortArray(t);
              return merge(a, b);                   

          }
      };
      
      Slower comparative to the other sort algorithms for smaller tasks.
      
      The merge sort algorithm requires an additional memory space of 0(n) for the temporary array.
      
      It goes through the whole process even if the array is sorted.
      
      
