
    Node* segregate(Node *head) {
        
        // Add code here
        struct Node *temp = head;
        int zero = 0, one = 0, two = 0;
        while(temp) {
            if(temp->data == 0) {
                zero++;
            }
            else if (temp->data == 1) {
                one++;
            }
            else {
                two++;
            }
            temp = temp->next;
        }
        temp = head;
        while(temp) {
            if(zero) {
                temp->data = 0;
                zero--;
            }
            else if (one) {
                temp->data = 1;
                one--;
            }
            else {
                temp->data = 2;
                two--;
            }
            temp = temp->next;
        }
        return head;
    }
