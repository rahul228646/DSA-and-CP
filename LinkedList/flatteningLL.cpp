
// https://www.geeksforgeeks.org/flattening-a-linked-list/
// Time : Θ(nlogn) 

Node *merge(Node *a, Node *b)
{
   struct Node * dummy = new Node(0);
   struct Node *ptr = dummy;
   while(a && b) {
       if(a->data <= b->data) {
           ptr->bottom = a;
           a = a->bottom;
       }
       else {
           ptr->bottom = b; 
           b = b->bottom;
       }
       ptr = ptr->bottom;
   }
   if(a) ptr->bottom = a;
   else ptr->bottom = b;
   return dummy->bottom;
}

Node *flatten(Node *root)
{
   if(!root || !root->next) return root;
   root->next = flatten(root->next);
   root = merge(root, root->next);
   return root;
}

