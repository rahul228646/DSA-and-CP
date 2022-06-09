# Notes

## STL

### Priority Queue :
    4 ways of implementing it -
                        Insert   Delete   Peek
        1. Array     -   O(1)     O(n)    O(n) 
        2. LinkList  -   O(n)     O(1)    O(1) 
        3. Heap      -   O(logn)  O(logn) O(n) 
        4. BST       -   O(logn)  O(logn) O(n) 

        (Bst -  Self-Balancing Binary Search Tree like AVL Tree, Red-Black Tree is used)

    priority_queue<int> pq - max heap (highest priority element on top)

    priority_queue <int, vector<int>,greater<int>> pq - min heap (lowest priority element on top)

### Custom Comparator for Priority Queue :
    
        class Foo{...};
        class Compare {
            public:
            bool operator() (Foo1, Foo2) {return Foo1<Foo2 // Foo2 will be on Top}
        };
        int main() {
            priority_queue<Foo, std::vector<Foo>, Compare> pq;
            return 0;
        }

### deque :

    Double-ended queues are sequence containers with the feature of expansion and contraction on both ends. 
    They are similar to vectors, but are more efficient in case of insertion and deletion of elements. Unlike vectors, 
    contiguous storage allocation may not be guaranteed. 

    Time Complexity of Operations -
        
        Accessing Elements- O(1)
        Insertion or removal of elements- O(N)
        Insertion or removal of elements at start or end- O(1)
