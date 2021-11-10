

    Node* rotate(Node* head, int k)
    {
        // Your code here
        Node *dummy = new Node(0);
        dummy->next = head;
        Node *temp;
        while(head->next) {
            if(k == 1) {
                temp = head;
            }
            head = head->next;
            k--;
        }
        head->next = dummy->next;
        dummy->next = temp->next;
        temp->next = nullptr;
        return dummy->next;
    }

// making ll circular

    Node* rotate(Node* head, int k)
    {
        // Your code here
        if(k == 0) return head;
        Node *curr = head;
        while(curr->next) curr = curr->next;
        
        curr->next = head;
        for(int i = 0; i<k; i++) curr = curr->next;
        head = curr->next;
        curr->next = nullptr;
        return head;
    
    }
