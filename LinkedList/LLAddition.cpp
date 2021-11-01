
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

// for o(1) space

// 1) Find the middle point using tortoise and hare method.
// 2) Split the linked list into two halves using found middle point in step 1.
// 3) Reverse the second half.
// 4) Do alternate merge of first and second halves.
  
Node *rev(Node * h) {
    if(!h || !h->next) return h;
    Node *x = rev(h->next);
    h->next->next = h;
    h->next = nullptr;
    return x;
}

Node *middle(Node *h) {
    Node *s=h, *f=h->next;
    while(s && f && f->next) {
        s=s->next;
        f=f->next->next;
    }
    return s;
}
Node *merge(Node *a, Node *b) {

    Node *h = a, *t = a;
    while(a||b) {
        if(b) {
            t->next = b;
            t = t->next;
            b = b->next;
        }
        if(a) {
            t->next = a;
            t = t->next;
            a = a->next;
        }
    }
    return h;
}
void reorderList(Node* h) {
    Node *mid = middle(h);
    Node *a = h, *b = mid->next;
    mid->next = nullptr;
    b = rev(b);
    h = merge(a, b);
    
}
