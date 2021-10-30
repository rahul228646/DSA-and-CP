
    Node *reverseLL(Node *h) {
        if(!h || !h->next) return h;
        Node * x = reverseLL(h->next);
        h->next->next = h;
        h->next = nullptr;
        return x;
    }
    Node *del(Node *h) {
        Node* current = h;
        Node* maxnode = h;
        Node* temp;
 
        while (current && current->next) {

            if (current->next->data < maxnode->data) {
                temp = current->next;
                current->next = temp->next;
                free(temp);
            }
 
            
            else
            {   
                current = current->next;
                maxnode = current;
            }
        }
        return h;
    }
    Node *compute(Node *h){
      // reverse ll since last element will never we deleted
        h = reverseLL(h);
        h = del(h);
      // reverse again to get back the original order
        h = reverseLL(h);
        return h;
    }
    
