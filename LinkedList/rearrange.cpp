
// 1->2->3->4
// 1->4->2->3
  
// Time : O(n) Space : O(n) (deque is used)
// https://www.geeksforgeeks.org/rearrange-a-given-linked-list-in-place/

void reorderList(Node* head) {
    // Your code herestruct Node*
    struct Node* temp = nullptr, *tail = nullptr;
    deque<struct Node*> dq;
    while(head) {
        dq.push_back(head);
        head = head->next;
    }
    while(!dq.empty()) {
        // cout<<dq.front()->data<<" "<<dq.back()->data<<endl;
        if(temp == nullptr) {
            temp = dq.front();
            tail = temp;
            dq.pop_front();
            if(dq.empty()) {
                tail->next = nullptr;
                break;
            }
            else {
                tail->next = dq.back();
                dq.pop_back();
                
            }
            tail = tail->next;
        }
        else {
            tail->next = dq.front();
            tail = tail->next;
            dq.pop_front();
            if(dq.empty()) {
                tail->next = nullptr;
                break;
            }
            else {
                tail->next = dq.back();
                dq.pop_back();
            }
            tail = tail->next;
        }
    }
    if(tail) tail->next = nullptr;
    head = temp;
    
}
