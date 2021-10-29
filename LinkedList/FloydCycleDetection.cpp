
https://www.geeksforgeeks.org/how-does-floyds-slow-and-fast-pointers-approach-work/

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
