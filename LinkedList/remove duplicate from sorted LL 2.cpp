https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

[1,2,3,3,4,4,5] ==> [1,2,5]

class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode *dummy, *prev;
        dummy = new ListNode(0);
        dummy->next = head;
        prev = dummy;
        while(head)
        {
            while(head->next!=NULL && head->val == head->next->val)
            {
                head = head->next;
            }
            if(prev->next == head)
                prev = prev->next;
            else
                prev->next = head->next;
            head = head->next;
        }
      
        return dummy->next;
        
    }
};

