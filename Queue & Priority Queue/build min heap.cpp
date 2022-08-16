// Time O(N)
// time complexity = summation(0, height) --> time to heapify * no of nodes a that level
// summation(0, log N) --> log N * [N/2^(logN+1)]  where N is total no of nodes
// the above equation == O(N)

void minHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
 void buldHeap(vector<int> &heap) {
   int heapSize = heap.size()-1;
   for(int i = heapSize/2-1; i>=0; i++) { // heapyfy from 2nd last level
     minHeapify(i)
   }
 }
