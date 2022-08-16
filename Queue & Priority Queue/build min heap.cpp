// Time O(N)


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
