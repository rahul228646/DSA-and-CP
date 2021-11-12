
// https://www.geeksforgeeks.org/merge-k-sorted-linked-lists/

// Time : O(n*k*logk) - at most k insertion at deletion into heap therefore log k and this happens for all elements so total time complexity is n*k * log k
// Space : O(k + n*k) - k for heap and n*k for output linklist

typedef pair<int, pair<int, Node*>> ppi;

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int k) {
        Node *resH, *resT;
        priority_queue<ppi, vector<ppi>, greater<ppi> > pq;
        for(int i = 0; i<k; i++) {
            // cout<<arr[i]->data<<endl;
            pq.push({arr[i]->data, {i, arr[i]}});
        }
        while(!pq.empty()) {
            ppi curr = pq.top();
            pq.pop();
 
            int i = curr.second.first;
            Node* temp = curr.second.second;
            if(!resH) {
                resH = temp;
                resT = temp; 
            }
            else {
                resT->next = temp;
                resT = resT->next;
            }
            if(temp->next) {
                pq.push({temp->next->data, {i, temp->next}});
            }
        }
        resT->next = nullptr;
        return resH;
    }
};
