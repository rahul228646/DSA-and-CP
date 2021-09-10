#include <iostream>
using namespace std;


// linked list implementation
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    
};


Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

//Length of LL
int length(Node *head) {
    Node *temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

//Print ith Node
void printIthNode(Node *head, int i) {
    int count = 0;
    Node *temp = head;

    while(temp!=NULL){
        if(count == i){
            cout<<temp->data;
            break;
        }
        count++;
        temp = temp->next;
    }
    
}

//Delete Node
Node* deleteNode(Node *head, int i) {
    Node *temp = head;
    if(i == 0){
        delete temp;
        head = head->next;
        return head;
    }

    int count = 0;
    while(temp != NULL){
        if(count == i-1){
            if(temp->next==NULL)
                break;
            Node *toBeDeleted = temp->next;
            temp->next = temp->next->next;
            delete toBeDeleted;
            return head;
        }
        temp = temp->next;
        count++;
    }
    return head;
}

//Insert Node (recursive)
Node* insertNodeRec(Node *head, int i, int data) {
    
    if(head == NULL)
        return NULL;
    if(i == 0){
        Node *newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }
    Node *temp = insertNodeRec(head->next, i-1, data);
    head->next = temp;
    return head;
}

//Delete Node (recursive)
Node* deleteNodeRec(Node *head, int i) {
    if(head == NULL)
        return NULL;
    if(i == 0){
        Node *toBeDeleted = head;
        head = head->next;
        delete toBeDeleted;
        return head;
    }
    Node *temp = deleteNodeRec(head->next, i-1);
    head->next = temp;
    return head;

}

//Find a Node in LL
//Given a linked list and an integer n you need to find and return index where n is present in the LL. Do this iteratively.Return -1 if n is not present in the LL.
int indexOfNIter(Node *head, int n) {
    if(head == NULL){
        return -1;
    }
    if(head->data == n)
        return 0;
    int ans = indexOfNIter(head->next, n);
    if(ans == -1)
        return ans;
    
    return ans+1;
}

//AppendLastNToFirst
//    1 2 3 4 5 -1
//    3
//    3 4 5 1 2

Node* append_LinkedList(Node* head, int n){
    Node *temp1 = head;
    Node *temp2, *temp3;
    int len = length(head);
    n = len - n;
    int count = 0;
    while(temp1->next != NULL){
        if(count == n-1){
            temp2 = temp1;
            temp3 = temp1->next;
            
        }
        temp1 = temp1->next;
        count++;
    }
    
    temp1->next = head;
    head = temp3;
    temp2->next = NULL;
    return head;
    
}

//Eliminate duplicates from LL
//    1 2 3 3 3 4 4 5 5 5 7 -1
//    1 2 3 4 5 7
Node* eliminate_duplicate(Node* head){
    Node *h1=head;
    Node *h2=head->next;
    
    while(h2!=NULL){
        
        if(h1->data == h2->data){
            Node *temp = h2;
            h2 = h2->next;
            delete temp;
        }
        else{
            h1->next = h2;
            h1 = h1->next;
            h2 = h2->next;
        }
    }
    h1->next=h2;
    return head;
}

//Print reverse LinkedList
void print_linkedlist_spl(Node*head){
    if(head == NULL)
        return;
    print_linkedlist_spl(head->next);
    cout<<head->data<<" ";
}



//Palindrome LinkedList
// o(n) time and o(1) space
class Solution {
    ListNode *curr;
public:
    bool isPalindromeUtil(ListNode *head) {
        if(head == NULL) return true;
        bool isPal = isPalindromeUtil(head->next);
        if(!isPal || curr->val != head->val) return false;
        curr = curr ->next;
        return true;
    }
    bool isPalindrome(ListNode* head) {
        curr = head;
        return isPalindromeUtil(head);
    }
};

// or
bool pal(Node *head,Node *h1)
{
    if(head==NULL||h1==NULL)
    {
        return true;
    }
    if(head->data==h1->data)
    {
        bool c=pal(head->next,h1->next);
        if(!c)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}
Node* rev_linkedlist_itr(Node* head) // reversing list from the mid
{
    Node *pre=NULL;
    Node *c=head;
    Node *n=head->next;
    while(c!=NULL)
    {
        n=c->next;
        c->next=pre;
        pre=c;
        c=n;
    }
    return pre;
}
Node* midpoint_linkedlist(Node *head) // fing the mid point
{
    // Write your code here
    Node *s=head;
    Node *f=head->next;
    while(f->next!=NULL && f!=NULL)
    {
        s=s->next;
        f=f->next->next;
    }
    return s;
}

bool check_palindrome(Node* head) // comparing the two list
{
    Node *t=midpoint_linkedlist(head);
    Node *h=t->next;
    Node *h1=rev_linkedlist_itr(h);
    
    bool b=pal(head,h1);
    return b;
    
}

//Code: Reverse LL (Iterative)
Node* revLinkedlistItr(Node* head){
    Node *current=head;
    Node *next;
    Node *prev=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}

//Code : Reverse LL (Recursive)
Node *reverse_linked_list_rec(Node *head){
    //write your recursive code here
    if(head->next==NULL)
        return head;
    
    Node *x=reverse_linked_list_rec(head->next);
    Node *temp = x;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;
    head->next=NULL;
    return x;
}
// or
Node *reverse_linked_list_rec2(Node *head){
    if(head == NULL){
        return head;
    }
    Node *temp = reverse_linked_list_rec2(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

//Code: Midpoint of LL
Node* midpointLinkedlist(Node *head){
    if(head == NULL || head->next == NULL)
        return head;
    Node *slow=head,*fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

//Even after Odd LinkedList (even no.s are placed after odd , no need to sort)
//    1 4 5 2 -1
//    1 5 4 2
Node* arrange_LinkedList(Node *head){
    
    Node *curr = head;
    Node *prev = NULL;
    Node *toBeChanged;
    while(curr != NULL){
        if(curr->data % 2 == 0 && curr == head){
            toBeChanged = curr;
            head = curr->next;
            head->next = toBeChanged;
            curr = head;
        }
        else if(curr->data % 2 == 0){
            
        }
  
        prev = curr;
        curr = curr->next;

    }
    return NULL;
}

//Delete every N Nodes
//    1 2 3 4 5 6 7 8 -1
//    2 (retain M)
//    2 (delete N)
//    1 2 5 6
Node* skipMdeleteN(Node  *head, int M, int N) {
    // Write your code here
    Node *temp=head;
    Node *t1;
    if(M==0)
    {
       return NULL;
    }
    
    while(temp!=NULL){
    int count=1;
    while(count<=M)
    {
        if(temp==NULL)
            break;
         t1=temp;
        temp=temp->next;
        count++;
    }
        
    count=1;
    while(count<=N)
    {
        if(temp==NULL)
            break;
        Node *del=temp;
        temp=temp->next;
        delete del;
        count++;
    }
    t1->next=temp;
    }
    return head;
}

//Swap two Node of LL
Node* swap_Nodes(Node *head,int i,int j)
{
    if(i==j)
       {
           return head;
       }
    //write your code here
    Node * temp=head;
    Node *p1=NULL,*p2=NULL,*c1=NULL,*c2=NULL,*f1=NULL;
    int count=0;
    int len = length(head);
    if(i>j)
    {
        int temp=i;
        i=j;
        j=temp;
    }
    
    if(j>=len)
        return head;
    
        if(i==0 && (j-i)!=1)
        {

            while(count<=j)
            {
                if(count==i)
                    c1=temp;
                if(count==i+1)
                    f1=temp;
                if(count==j-1)
                    p2=temp;
                if(count==j)
                    c2=temp;
                temp=temp->next;
                count++;
            }
            
            
            p2->next=c1;
            c1->next=c2->next;
            c2->next=f1;
            head=c2;
        }
        
     else if(i==0 && (j-i) ==1)
        {

            while(count<=j)
            {
                
                if(count==i)
                    c1=temp;
                if(count==j)
                    c2=temp;
                temp=temp->next;
                count++;
            }
            
            c1->next=c2->next;
            c2->next=c1;
            head=c2;
        }
        
       else if((j-i)==1)
        {

           while(count<=j)
            {
                if(count==i-1)
                    p1=temp;
                if(count==i)
                    c1=temp;
                if(count==j)
                    c2=temp;
                temp=temp->next;
                count++;
            }
            
            p1->next=c2;
            c1->next=c2->next;
            c2->next=c1;
        }
        
        else
        {

            while(count<=j)
            {
                if(count==i-1)
                    p1=temp;
                if(count==i)
                    c1=temp;
                if(count==i+1)
                    f1=temp;
                if(count==j-1)
                    p2=temp;
                if(count==j)
                    c2=temp;
                temp=temp->next;
                count++;
            }
            
            
            p1->next=c2;
            p2->next=c1;
            c1->next=c2->next;
            c2->next=f1;
        }
   
    return head;
}

//kReverse
//    1 2 3 4 5 6 7 8 9 10 -1
//    4
//    4 3 2 1 8 7 6 5 10 9
Node *end(Node *head)
{
    while(head->next!=NULL)
        head=head->next;
    return head;
}
Node *Krev(Node *head, int n){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *h1=head;
    Node *t1=head;
    int count = 1;
    while(count < n){
        if(t1 == NULL)
            break;
        t1 = t1->next;
        count++;
    }
    Node *h2 = t1->next;
    t1->next = NULL;
    h1 = reverse_linked_list_rec(h1);
    t1 = end(h1);
    Node *ans = Krev(h2, n);
    t1->next = ans;
    return h1;
}

int main() {
    Node* head=takeinput();
    int m,n;
    cin>>m >> n;
    head= swap_Nodes(head,m,n);
    print(head);
    return 0;
}
