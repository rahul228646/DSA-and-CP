#include <iostream>
#include <queue>
#include <vector>
using namespace std;


//BST
//      root (greater than left)
//      /  \
//   left   right

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
    ~BinaryTreeNode() {
        if(left)
               delete left;
        if(right)
               delete right;
    }
};


BinaryTreeNode<int>* takeInput() {
    int rootData;
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
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

//Code: Search in BST
BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int> *root , int k){
    if(root == NULL)
        return NULL;
    if(root->data == k)
        return root;
    else if(root->data < k)
        return searchInBST(root->right, k);
    else
        return searchInBST(root->left, k);
    
}

//Code: Print Elements in Range
void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2){
    if(root == NULL)
        return;
    if(root->data >= k1 && root->data <= k2){
        elementsInRangeK1K2(root->left, k1, k2); // this is to print in increasing order
        cout<<root->data<<" "; // this alone will print in random order
        elementsInRangeK1K2(root->right, k1, k2); //this is to print in increasing order
    }
    else if(root->data < k1)
        elementsInRangeK1K2(root->right, k1, k2);
    else if(root->data > k2)
         elementsInRangeK1K2(root->left, k1, k2);
}

//Check if a Binary Tree is BST
bool isBST3(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX) {
    if (root == NULL) {
        return true;
    }
    if (root->data < min || root->data > max) {
        return false;
    }
    bool isLeftOk = isBST3(root->left, min, root->data);
    bool isRightOk = isBST3(root->right, root->data, max);
    return isLeftOk && isRightOk;
}



bool isBST(BinaryTreeNode<int> *root){
    

    return isBST3(root);
}

//Code: Construct BST from a Sorted Array (mid is root)
BinaryTreeNode<int>* constructTreehelper(int *input, int start, int end) {
    if(start > end)
        return NULL;
    int mid = (start+end)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int> (input[mid]);
    BinaryTreeNode<int> *left = constructTreehelper(input, start, mid-1);
    BinaryTreeNode<int> *right = constructTreehelper(input, mid+1, end);
    
    root->left = left;
    root->right = right;
    
    return root;
}

BinaryTreeNode<int>* constructTree(int *input, int n){
    return constructTreehelper(input, 0 , n-1);
}

//Code: BST to Sorted LL
template <typename T>
class Node{
   public:
   T data;
   Node<T> *next;
   
   Node(T data){
       this -> data = data;
       this -> next = NULL;
   }
};

Node<int>* constructBST1(BinaryTreeNode<int>* root) {

    if(root == NULL)
        return NULL;
    
    Node<int> *left = constructBST1( root->left);
    Node<int> *middle = new Node<int> (root->data);
    Node<int> *right = constructBST1( root->right);
    Node<int> *temp = left;
    
    if(left == NULL){
        left = middle;
    }
    else{
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = middle;
    }
    
    middle->next = right;
    
    return left;
    
}

//Find Path in BST
vector<int>* findPath(BinaryTreeNode<int> *root , int data){
 
    if(root == NULL)
        return NULL;
    
    if(root->data == data){
        vector<int> *output = new vector<int>;
        output->push_back(root->data);
        return output;
    }
    
    if(root->data > data){
        vector<int> *leftoutput = findPath(root->left ,data);
        if(leftoutput != NULL){
            leftoutput->push_back(root->data);
            return leftoutput;
        }
    }
    else{
        vector<int> *rightoutput = findPath(root->right ,data);
        if(rightoutput != NULL){
            rightoutput->push_back(root->data);
            return rightoutput;
        }
    }
    return NULL;
}

//Create & Insert Duplicate Node
//Given a Binary Tree with N number of nodes, for each node create a new duplicate node, and insert that duplicate as left child of the original node.
void insertDuplicateNode(BinaryTreeNode<int> *root) {
    if(root == NULL)
        return;
    insertDuplicateNode(root->left);
    insertDuplicateNode(root->right);
    BinaryTreeNode<int>* copy = new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int> *temp = root->left;
    root->left = copy;
    copy->left = temp;
    return ;
}

//Pair sum BInary Tree
void cvt(vector<int> &arr ,BinaryTreeNode<int> *root ){
    if(root == NULL)
        return;
    
    arr.push_back(root->data);
    cvt(arr, root->left);
    cvt(arr, root->right);

   
}

void nodesSumToS(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    vector<int> arr;
    cvt(arr,root);
    sort(arr.begin(),arr.end());
    int i=0,j=arr.size()-1;
    while(i<j){
        if(arr.at(i)+arr.at(j) == sum){
            cout<<arr.at(i)<<" "<<arr.at(j)<<endl;
            i++;
            j--;
        }
        else if(arr.at(i)+arr.at(j) >= sum){
            j--;
        }
        else{
            i++;
        }
    }

}

//LCA of Binary Tree
//    5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
//    2 10
//    10

//    5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
//    2 6
//    5
BinaryTreeNode <int>* helper(BinaryTreeNode <int>* root , int val1, int val2){
    if(root == NULL)
        return NULL;
    if(root->data == val1 || root->data == val2)
        return root;
    
    BinaryTreeNode <int>* left = helper(root->left ,val1,val2);
    BinaryTreeNode <int>* right = helper(root->right ,val1,val2);
    
    if(left == NULL && right == NULL)
        return NULL;
    else if(left != NULL && right != NULL)
        return root;
    else if(left == NULL && right != NULL)
        return right;
    else
        return left;
    
}

int lcaBinaryTree(BinaryTreeNode <int>* root , int val1, int val2){
    
    BinaryTreeNode <int>* ans = helper(root,val1,val2);
    if(ans!=NULL)
        return ans->data;
    else
        return -1;
    
}

//LCA of BST
BinaryTreeNode <int>* helperBst(BinaryTreeNode <int>* root , int val1, int val2){
    // Write your code here
    if(root == NULL)
        return NULL;

    
    if(root->data == val1 || root->data == val2)
        return root;
    
    else if((root->data > val1 && root->data > val2))
         return helper(root->left ,val1,val2);
    
    else if((root->data < val1 && root->data < val2))
        return helper(root->right ,val1,val2);
    
    else {
        BinaryTreeNode <int>* a = helperBst(root->left ,val1,val2);
        BinaryTreeNode <int>* b = helperBst(root->right ,val1,val2);
    
    if(a!=NULL && b!=NULL)
        return root;
    else if(a==NULL && b==NULL)
        return NULL;
    else if(a!=NULL && b==NULL)
        return a;
    else
        return b;
    }
    
}

int lcaInBST(BinaryTreeNode <int>* root , int val1, int val2){
    
    BinaryTreeNode <int>* ans = helperBst(root,val1,val2);
    if(ans!=NULL)
        return ans->data;
    else
        return -1;
    
}

//Replace with Sum of greater nodes
int replaceWithLargerNodesSum(BinaryTreeNode<int> *root, int sum){
    if(root == NULL)
        return sum;
    sum = replaceWithLargerNodesSum(root->right, sum);
    sum += root->data;
    root->data = sum;
    sum = replaceWithLargerNodesSum(root->left, sum);
    return sum;
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root){
    replaceWithLargerNodesSum(root, 0);
}

//Largest BST
//Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree.
class lBst {
public:
    int min;
    int max;
    bool isBST;
    int height;
};

lBst largestBSTSubtreehelper(BinaryTreeNode<int> *root) {
    if(root==NULL){
        lBst p;
        p.min = INT_MAX;
        p.max = INT_MIN;
        p.isBST = true;
        p.height = 0;
        return p;
    }
    
    lBst left = largestBSTSubtreehelper(root->left);
    lBst right = largestBSTSubtreehelper(root->right);
    lBst ans;
    ans.min = min(left.min, min(right.min,root->data));
    ans.max = max(left.max, max(right.max,root->data));
    ans.isBST = (left.isBST && right.isBST) && (left.max < root->data && right.min > root->data);
    
    if(ans.isBST)
        ans.height = max(left.height ,right.height) + 1;
    else
        ans.height = max(left.height ,right.height);
    
    return ans;
}

//Path Sum Root to Leaf
//Given a binary tree and a number k, print out all root to leaf paths where the sum of all nodes value is same as the given number k.
# include<string.h>
void printPath(BinaryTreeNode<int> *root,int k,string ans){
    if(root==NULL){
        return;
    }
    else if(root->left==NULL && root->right==NULL){
        if(root->data==k){
            cout<<ans<<root->data<<endl;
        }
        return;
    }
    string rootData=to_string(root->data);
    printPath(root->left,k-root->data,ans+rootData+" ");
    printPath(root->right,k-root->data,ans+rootData+" ");
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    printPath(root,k,"");
}

//Print nodes at distance k from node
//Given a binary tree, a node and an integer K, print nodes which are at K distance from the the given node
void nodesAtDistanceKDown(BinaryTreeNode<int> *root, int k) {
    if(root == NULL)
        return;
    if(k == 0){
        cout<<root->data<<endl;
        return;
    }
    nodesAtDistanceKDown(root->left, k-1);
    nodesAtDistanceKDown(root->right, k-1);
}

int nodesAtDistanceKHelper(BinaryTreeNode<int> *root, int target, int k) {
    if(root == NULL)
        return -1;
    if(root->data == target){
        nodesAtDistanceKDown(root, k);
        return 0;
    }
    
    int leftD = nodesAtDistanceKHelper(root->left, target, k);
    
    if(leftD != -1){
        if(leftD + 1 == k){
            cout<<root->data<<endl;
        }
        else
            nodesAtDistanceKDown(root->right, k - leftD - 2);
        return 1 + leftD;
    }
    
    int rightD = nodesAtDistanceKHelper(root->right, target, k);
    
    if(rightD != -1){
        if(rightD + 1 == k){
            cout<<root->data<<endl;
        }
        else
            nodesAtDistanceKDown(root->right, k - rightD - 2);
        return 1 + rightD;
    }
    
    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    nodesAtDistanceKHelper(root, node, k);
}




int largestBSTSubtree(BinaryTreeNode<int> *root){
   return largestBSTSubtreehelper(root).height;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
