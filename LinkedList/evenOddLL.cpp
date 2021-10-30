

    Node* divide(int N, Node *head){
        Node *even = nullptr, *odd = nullptr;
        Node *evenTail = nullptr, *oddTail = nullptr;
        while(head) {
            if(head->data % 2 == 0) {
                if(even == nullptr) {
                    even = head;
                    evenTail = head;
                }
                else {
                    evenTail->next = head;
                    evenTail = head;
                }
            }
            else {
                if(odd == nullptr) {
                    odd = head;
                    oddTail = head;
                }
                else {
                    oddTail->next = head;
                    oddTail = head;
                }
            }
           head = head->next; 
        }
        if(even) {
            evenTail->next = odd;
            if(oddTail) oddTail->next = nullptr;
            return even;
        }
        else {
            if(oddTail) oddTail->next = nullptr;
            return odd;
        }
        return nullptr;
    }
