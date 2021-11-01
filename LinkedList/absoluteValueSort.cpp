
// Input : 1 -> -2 -> -3 -> 4 -> -5 
// output: -5 -> -3 -> -2 -> 1 -> 4 

// An important observation is, all negative elements are present in reverse order. 
// So we traverse the list, whenever we find an element that is out of order, we move it to the front of the linked list  

// Time : O(n) space : O(1)
// https://www.geeksforgeeks.org/sort-linked-list-already-sorted-absolute-values/
  
void sortList(Node** head)
{
    // Initialize previous and current nodes
    Node* prev = (*head);
    Node* curr = (*head)->next;
 
    // Traverse list
    while (curr != NULL)
    {
        // If curr is smaller than prev, then
        // it must be moved to head
        if (curr->data < prev->data)
        {
            // Detach curr from linked list
            prev->next = curr->next;
 
            // Move current node to beginning
            curr->next = (*head);
            (*head) = curr;
 
            // Update current
            curr = prev;
        }
 
        // Nothing to do if current element
        // is at right place
        else
            prev = curr;
 
        // Move current
        curr = curr->next;
    }
}
 
