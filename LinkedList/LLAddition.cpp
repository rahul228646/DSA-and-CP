
  int len(Node* h) {
        int cnt = 0;
        while(h) {
            cnt++;
            h = h->next;
        }
        return cnt;
    }
    Node *reverseLL(Node *h) {
        if(!h || !h->next) return h;
        Node * x = reverseLL(h->next);
        h->next->next = h;
        h->next = nullptr;
        return x;
    }
    struct Node* addTwoLists(struct Node* f, struct Node* s) {
        int l1 = len(f), l2 = len(s), carry = 0;
        f = reverseLL(f);
        s = reverseLL(s);
        if(l1<l2) {
            Node *t = f;
            f = s;
            s = t;
        }
        Node *h = f, *t = f;
        while(f) {
            if(s) {
                int x = f->data + s->data + carry;
                f->data = x%10;
                carry = x/10;
                s = s->next;
            }
            else {
               if(!carry) break;
               int x = (f->data+carry);
               f->data = x%10;
               carry = x/10;
            }
            t = f;
            f = f->next;
        }
        
        if(carry) {
            Node *newNode = new Node(carry);
            t->next = newNode;
            newNode->next = nullptr;
        }
        h = reverseLL(h);
        return h;
    }
