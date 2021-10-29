
// https://www.geeksforgeeks.org/how-does-floyds-slow-and-fast-pointers-approach-work/

// Time - O(N) Space - O(1)

// 1) When slow pointer enters the loop, the fast pointer must be inside the loop. Let fast pointer be distance k from slow.
// 2) Now if consider movements of slow and fast pointers, we can notice that distance between them (from slow to fast) 
//    increase by one after every iteration. After one iteration (of slow = next of slow and fast = next of next of fast), 
//    distance between slow and fast becomes k+1, after two iterations, k+2, and so on. When distance becomes n, 
//    they meet because they are moving in a cycle of length n.

    bool detectLoop(Node* head)
    {
        // your code here
        Node* s = head;
        Node* f = head->next;
        while(s && f && f->next) {
            if(s==f) return true;
            s = s->next;
            f = f->next->next;
        }
        return false;
    }
