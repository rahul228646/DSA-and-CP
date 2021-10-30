
// https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/

// - Get count of the nodes in the first list, let count be c1.
// - Get count of the nodes in the second list, let count be c2.
// - Get the difference of counts d = abs(c1 – c2)
// - Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal no of nodes
//   Then we can traverse both the lists in parallel till we come across a common node. 
//   (Note that getting a common node is done by comparing the address of the nodes)

int intersectPoint(Node* h1, Node* h2)
{
    Node *t1 = h1 , *t2 = h2;
    int c1 = 0, c2 = 0, diff = 0;
    while(t1) {
        t1=t1->next;
        c1++;
    }
    while(t2) {
        t2=t2->next;
        c2++;
    }
    diff = abs(c1-c2);
    t1 = (c1>c2) ? h1 : h2;
    t2 = (c1>c2) ? h2 : h1;
    while(diff) {
        t1=t1->next;
        diff--;
    }
    while(t1&&t2) {
        if(t1==t2) return t1->data;
        t1=t1->next;
        t2=t2->next;
    }
    return -1;
}
