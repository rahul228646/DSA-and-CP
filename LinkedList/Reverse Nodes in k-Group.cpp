https://leetcode.com/problems/reverse-nodes-in-k-group/

class Solution {
public:
    ListNode* rev(ListNode* h) {
        if(!h || !h->next) return h;
        auto nxt = rev(h->next);
        h->next->next = h;
        h->next = nullptr;
        return nxt;
    }
    ListNode* reverseKGroup(ListNode* h, int k) {
        auto currH = h, last = h, res = new ListNode(0);
        res->next = h;
        auto temp = res;
        int i = 1;
        while(last) {
            if(i==k) {
                ListNode* tT = last->next;
                last->next = nullptr;
                temp->next = rev(currH);
                temp = currH;
                currH->next = tT;
                currH = tT;
                last = tT;
                i = 1;
            }
            if(!last) break;
            last = last->next;
            i++;
        }
        
        return res->next;
    }
};
