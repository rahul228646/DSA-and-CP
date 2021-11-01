
// https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1
// Time : O(nLogn) space : O(nLogn)
// check these as well : https://www.geeksforgeeks.org/point-to-next-higher-value-node-in-a-linked-list-with-an-arbitrary-pointer/, 
//                       https://www.geeksforgeeks.org/find-a-triplet-from-three-linked-lists-with-sum-equal-to-a-given-number/
    Node *middle(Node *h) {
        Node *slow = h;
        Node *fast = h->next;
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node *merge(Node *a, Node *b) {
        Node *resH = nullptr, *resT = nullptr;
        while(a && b) {
            Node *x = nullptr;
            if(a->data <= b->data) {
                x = a;
                a = a->next;
            }
            else {
                x = b;
                b = b->next;
            }
            
            if(!resH) {
                resH = x;
                resT = x;
            }
            else {
                resT->next = x;
                resT = x;
            }
        }
        resT->next = (a)?a:b;
        return resH;
    }
    Node* mergeSort(Node* h) {
        // your code here
        if(!h || !h->next) return h;
        Node *a, *b;
        Node *mid = middle(h);
        a = h;
        b = mid->next;
        mid->next = nullptr;
        a = mergeSort(a);
        b = mergeSort(b);
        h = merge(a, b);
        return h;
    }
