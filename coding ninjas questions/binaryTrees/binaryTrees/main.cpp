#include <iostream>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// binary tree

//        root
//        /  \
//     left  right

template <typename T>
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

// levelwise input
BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
    q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

//Print Level Wise
void printLevelWise(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        
        BinaryTreeNode<int> *front = pendingNodes.front();
        cout<<front->data<<":";
        pendingNodes.pop();
        
        if(front->left != NULL){
            cout<<"L:"<<front->left->data;
        }
        else
            cout<<"L:"<<-1;
        
        if(front->right != NULL){
            cout<<",";
            cout<<"R:"<<front->right->data;
        }
        else
            cout<<",R:"<<-1;
        cout<<endl;
    }
}

//Code : Find a node
bool isNodePresent(BinaryTreeNode<int>* root, int x) {
    if(root == NULL)
        return false;
    
    if(root->data == x)
        return true;
    
    bool leftAns = isNodePresent(root->left, x);
    bool rightAns = isNodePresent(root->right, x);
    
//    if(leftAns || rightAns)
//        return true;
//    else
//        return false;
    
//    or
    
    return leftAns || rightAns;
}

//Code : Height of Binary Tree
int height(BinaryTreeNode<int> *root){
    if(root == NULL)
        return 0;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return max(leftHeight, rightHeight) + 1;
}

//Code : Mirror
//Mirror the given binary tree. That is, right child of every nodes should become left and left should become right.
void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if(root == NULL)
        return ;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    
    if(root->left!=NULL || root->right!=NULL){
        BinaryTreeNode<int>* temp = root->right;
        root->right = root->left;
        root->left = temp;
    }
}

//Preorder Binary Tree
//Pre-order traversal is: Root LeftChild RightChild
//8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
//8 3 1 6 4 7 10 14 13
void preOrder(BinaryTreeNode<int> *root) {
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

//Postorder Binary Tree
//Post-order traversal is: LeftChild RightChild Root
//8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
//1 4 7 6 3 13 14 10 8
void postOrder(BinaryTreeNode<int> *root) {
    if(root == NULL)
        return;
  
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

//Min and Max of Binary Tree
pair<int, int> minMax(BinaryTreeNode<int> *root) {
    if(root == NULL){
        pair<int, int> p;
        p.first = INT_MIN; // first is max
        p.second = INT_MAX;
        return p;
    }
    pair<int, int> left = minMax(root->left);
    pair<int, int> right = minMax(root->right);
    
    int maxAns = max(root->data,max(left.first , right.first));
    int minAns = min(root->data,min(left.second , right.second));
       
    pair<int, int> p;
    p.first = maxAns;
    p.second = minAns;
    return p;
}

//Sum of all nodes
int sumOfAllNodes(BinaryTreeNode<int>* root){
    if(root == NULL)
        return 0;
    return root->data + sumOfAllNodes(root->left) + sumOfAllNodes(root->right);
}
//is Balanced
//Given a binary tree, check if its balanced i.e. depth of left and right subtrees of every node differ by at max 1. Return true if given binary tree is balanced, false otherwise.
bool isBalanced(BinaryTreeNode<int> *root){
    if(root == NULL)
        return true;
    int hL = height(root->left);
    int hR = height(root->right);
    if(abs(hL - hR) > 1)
        return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

//Level order traversal
//  5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
//  5
//  6 10
//  2 3
//  9
void printLevelATNewLine(BinaryTreeNode<int> *root){
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while (!pendingNodes.empty()) {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
// this step is to introduce a space between a root and its children
         if(front==NULL){
             if(pendingNodes.empty())
                 break;
        
             cout<<endl;
             pendingNodes.push(NULL);
             continue;
         }
        cout<<front->data<<" ";
        if(front->left!=NULL){
            pendingNodes.push(front->left);
        }
        if(front->right!=NULL){
            pendingNodes.push(front->right);
        }
              
    }
}

//Remove Leaf nodes
BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    if(root == NULL)
        return NULL;
    if(root->left == NULL && root->right == NULL)
        delete root;
    BinaryTreeNode<int>* left = removeLeafNodes(root->left);
    BinaryTreeNode<int>* right = removeLeafNodes(root->right);
    root->left = left;
    root->right = right;
    
    return root;
}

//Nodes without sibling
void nodesWithoutSibling(BinaryTreeNode<int> *root) {
    if(root == NULL)
        return;
    if(root->left == NULL ^ root->right == NULL){
        if(root->left!=NULL)
            cout<<root->left->data<<endl;
        else
            cout<<root->right->data<<endl;
    }
    nodesWithoutSibling(root->left);
    nodesWithoutSibling(root->right);
}

//ZigZag tree
//Given a binary tree, print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
//    5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
//    5
//    10 6
//    2 3
//    9
void zigZagOrder(BinaryTreeNode<int> *root){
    stack<BinaryTreeNode<int>*> s1,s2;
    s1.push(root);
    while(s1.empty() == false ^ s2.empty() == false){
        while(s1.empty() == false){
                  cout<<s1.top()->data<<" ";
                  if(s1.top()->left != NULL)
                      s2.push(s1.top()->left);
                  if(s1.top()->right != NULL)
                      s2.push(s1.top()->right);
                  s1.pop();
        }
              cout<<endl;
        while(s2.empty() == false){
            cout<<s2.top()->data<<" ";
            if(s2.top()->right != NULL)
                s1.push(s2.top()->right);
            if(s2.top()->left != NULL)
                s1.push(s2.top()->left);
            s2.pop();
        }
        cout<<endl;
    }
}

//Code: Construct Tree from Preorder and Inorder
BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE) {
    if (inS > inE) {
        return NULL;
    }

    int rootData = pre[preS];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++) {
        if (in[i] == rootData) {
            rootIndex = i;
            break;
        }
    }

    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreS = preS + 1;
    int lPreE = lInE - lInS + lPreS;
    int rPreS = lPreE + 1;
    int rPreE = preE;
    int rInS = rootIndex + 1;
    int rInE = inE;
    BinaryTreeNode<int>*  root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
    return root;
}

//Construct Tree from Postorder and Inorder
BinaryTreeNode<int>* buildTreeHelper(int* in, int* post, int inS, int inE, int postS, int postE) {
    if (inS > inE || postS > postE) {
        return NULL;
    }

    int rootData = post[postE];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++) {
        if (in[i] == rootData) {
            rootIndex = i;
            break;
        }
    }


    int lInS = inS;
    int lInE = rootIndex - 1;
    int lpostS = postS;
    int lpostE = lInE - lInS + lpostS;
    int rpostS = lpostE + 1;
    int rpostE = postE - 1;
    int rInS = rootIndex + 1;
    int rInE = inE;
    BinaryTreeNode<int>*  root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(in, post, lInS, lInE, lpostS, lpostE);
    root->right = buildTreeHelper(in, post, rInS, rInE, rpostS, rpostE);
    return root;
}

BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
 int size = inLength;
    return buildTreeHelper(inorder, postorder, 0, size - 1, 0, size - 1);
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLenght, int *inorder, int inLength) {
    int size = inLength;
    return buildTreeHelper(inorder, preorder, 0, size - 1, 0, size - 1);
    
}

//Level wise linkedlist
//Send Feedback
//Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
template <typename T>
class node{
public:
    T data;
    node<T> * next;
    node(T data){
        this->data=data;
        this->next=NULL;
    }
};

vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
    
    node<int> *head = NULL , *tail = NULL;
    vector<node<int>*> output;
    queue<BinaryTreeNode<int>*> pendingNodes;
       pendingNodes.push(root);
       pendingNodes.push(NULL);
    
       while(pendingNodes.empty()!=true){
           
           BinaryTreeNode<int> *front = pendingNodes.front();
           pendingNodes.pop();
           if(front==NULL){
               output.push_back(head);
               head = NULL;
               tail = NULL;
               if(pendingNodes.empty())
                   break;
               
               pendingNodes.push(NULL);
               continue;
           }
           node<int> *newnode = new node<int>(front->data);
           if(head==NULL){
               head = newnode;
               tail = newnode;
               newnode->next = NULL;
           }
           else{
               tail->next = newnode;
               tail = newnode;
               newnode->next = NULL;
           }
           
           if(front->left!=NULL){
               pendingNodes.push(front->left);
           }
          
           if(front->right!=NULL){
               pendingNodes.push(front->right);
           }
           
       
       }

    return output;
}



int main() {
    BinaryTreeNode<int>* root = takeInput();
    pair<int, int> ans = minMax(root);
    cout << ans.first << " " << ans.second << endl;
}


