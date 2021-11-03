

Node* revLL(Node *h) {
    if(!h || !h->next) return h;
    Node *x = revLL(h->next);
    h->next->next = h;
    h->next = nullptr;
    return x;
}
int len(Node *h) {
    int count = 0;
    while(h) {
        h = h->next;
        count++;
    }
    return count;
}
bool l1Greater(Node *l1, Node *l2) {
    while(l1) {
        if(l1->data > l2->data) return true;
        if(l1->data < l2->data) return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    return true;
} 
Node* subLinkedList(Node* l1, Node* l2)
{
//   remove zeroes in front
    while(l1 && l1->data == 0) l1 = l1->next;
    while(l2 && l2->data == 0) l2 = l2->next;
//   calc len
    int len1 = len(l1), len2 = len(l2);
//   we need l1 to be of greater val
    if(len1<len2) swap(l1, l2);
    else if (len1 == len2) if(!l1Greater(l1,l2)) swap(l1, l2);
// reverse the ll cause we start subtracting from the last
    l1 = revLL(l1);
    l2 = revLL(l2);
  
    Node *h = l1;
    int borrow = 0;
    while(l1) {
        if(l2) {
            l1->data = l1->data - l2->data - borrow;
            if(l1->data < 0) {
                l1->data += 10;
                borrow = 1;
            }
            else {
                borrow = 0;
            }
            l2 = l2->next;
        }
        else {
            l1->data = l1->data - borrow;
            if(l1->data < 0) {
                l1->data += 10;
                borrow = 1;
            }
            else {
                borrow = 0;
            }
        }
        l1 = l1->next;
    }
//   return the list in original order
    h = revLL(h);
//   now if the leading digit is zero or whole digit is zero then we delete those
    while(h && h->data == 0) h = h->next;
//   if l1 and l2 were equal then the above step deleted all ll, therefore we need to create a node with 0 val and return it
    if(!h) {
        h = new Node(0);
    }
  
    return h;
}
