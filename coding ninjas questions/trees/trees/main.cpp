
#include <iostream>
using namespace std;
#include <vector>
#include <queue>

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
    
};

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

//Print Level Wise
//    10 3 20 30 40 2 40 50 0 0 0 0
//    10:20,30,40
//    20:40,50
//    30:
//    40:
//    40:
//    50:
void printLevelWise(TreeNode<int>* root) {
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        
        for(int i = 0; i < front->children.size(); i++){
            cout<<front->children[i]->data;
            pendingNodes.push(front->children[i]);
            if(i!=front->children.size()-1)
            cout<<",";
        }
        cout<<endl;
    }
    return;
}

//Find sum of nodes
int sumOfNodes(TreeNode<int>* root) {
    if(root == NULL)
        return 0;
    int nodeSum = 0;
    for (int i = 0; i<root->children.size(); i++) {
        nodeSum += sumOfNodes(root->children[i]);
    }
    return nodeSum + root->data;
}

//Max data node
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    if(root == NULL)
        return NULL;
    TreeNode<int>* max = root;
    for(int i = 0; i<root->children.size(); i++){
        if(max->data < maxDataNode(root->children[i])->data)
            max = maxDataNode(root->children[i]);
    }
    
    return max;
}

//Code : Find height
int height(TreeNode<int>* root) {
   
    if(root==NULL)
        return 0;
    
    int length=0;
    for(int i =0 ; i<root->children.size(); i++){
        if(length < height(root->children[i]))
            length = height(root->children[i]);
    }
    return length+1;
}

//Code : Count leaf nodes
int numLeafNodes(TreeNode<int>* root) {
    if(root == NULL)
        return 0;
    int ans = 0;
    for(int i =0 ; i<root->children.size(); i++){
        ans += numLeafNodes(root->children[i]);
    }
    if(root->children.size() == 0)
        return ans+1;
    else
        return ans;
}

//PostOrder Traversal
//    10 3 20 30 40 2 400 50 0 0 0 0
//    400 50 20 30 40 10
void postOrder(TreeNode<int>* root) {
    if(root->children.size()==0)
    {
        cout<<root->data<<" ";
        return;
    }
    for(int i=0;i<root->children.size();i++){
        postOrder(root->children[i]);
    }
    cout<<root->data<<" ";
}

//Contains x
bool containsX(TreeNode<int>* root, int x) {
    if(root == NULL)
        return false;
    if(root->data == x)
        return true;

    for(int i=0;i<root->children.size();i++){
        if(containsX(root->children[i], x))
            return true;
    }
    return false;
}

//Count nodes
int nodesGreaterThanX(TreeNode<int> *root, int x){
    if(root == NULL)
        return 0;
    int ans = 0;
    for(int i=0;i<root->children.size();i++){
        ans += nodesGreaterThanX(root->children[i], x);
    }
    if(root->data > x)
        return ans + 1;
    else
        return ans;
}

//Structurally identical
//Given two Generic trees, return true if they are structurally identical i.e. they are made of nodes with the same values arranged in the same way.
bool isIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if(root1 == NULL && root2 == NULL)
        return true;
    
    if(root1 == NULL ^ root2 == NULL)
        return false;
    
    if(root1->children.size() != root1->children.size())
        return false;
    
    if(root1->data != root2->data)
        return false;
    
    for(int i=0;i<root1->children.size();i++){
        if(!isIdentical(root1->children[i], root2->children[i]))
            return false;
    }
    
    return true;
}

//Next larger
//Given a generic tree and an integer n. Find and return the node with next larger element in the Tree i.e. find a node with value just greater than n.

TreeNode<int>* nextLargerElement(TreeNode<int> *root, int x) {
    if(root == NULL)
        return NULL;
    
    TreeNode<int> *nextLarger = NULL;
    if(root->data > x)
        nextLarger = root;

    for(int i=0; i < root->children.size(); i++){
        TreeNode<int>* temp = nextLargerElement(root->children[i], x);
        if(nextLarger == NULL)
            nextLarger = temp;
        else if(temp != NULL && temp->data > x && temp->data < nextLarger->data)
            nextLarger = temp;
    }
    return nextLarger;
}

//Replace with depth

//In a given Generic Tree, replace each node with its depth value. You need to just update the data of each node, no need to return or print anything.
//10 3 20 30 40 2 40 50 0 0 0 0
//0
//1 1 1
//2 2
void replaceWithDepthValue(TreeNode<int> *root, int depth = 0){
    
    if(root==NULL)
        return;
    root->data = depth;
    
    for(int i=0; i<root->children.size(); i++)
        replaceWithDepthValue(root->children[i], depth+1);
}

//Second Largest Element In Tree

//Given a generic tree, find and return the node with second largest value in given tree. Return NULL if no node with required value is present.
pair<TreeNode<int>* , TreeNode<int>*> helperSL(TreeNode<int> *root){   //pair class
    if(root == NULL){
        pair<TreeNode<int>*, TreeNode<int>*> p;
        p.first = NULL;
        p.second = NULL;
        return p;
    }
    
    pair<TreeNode<int>*, TreeNode<int>*> ans;
    ans.first = root;
    ans.second = NULL;
    
    for(int i = 0 ; i<root->children.size() ; i++){
        pair<TreeNode<int>*, TreeNode<int>*> temp = helperSL(root->children[i]);
       
              
        
        if(ans.first->data < temp.first->data){
            
            TreeNode<int> *t = ans.first;
            ans.first = temp.first;
            
            if(ans.second != NULL){
                if(temp.second != NULL){
                    if(t->data > ans.second->data){
                        if(t->data > temp.second->data){
                            ans.second = t;
                        }
                        else if(t->data < temp.second->data)
                            ans.second = temp.second;
                    }
                    else if(t->data < ans.second->data){
                        if(ans.second < temp.second)
                            ans.second = temp.second;
                    }
                        
                }
                else{
                    if(ans.second->data < t->data){
                        ans.second = t;
                    }
                }
            }
            else{
                if(temp.second != NULL){
                    if(temp.second->data > t->data){
                        ans.second = temp.second;
                    }
                    else
                        ans.second = t;
                }
                else{
                    ans.second = t;
                }
            }
        }
        
        else if(ans.first->data > temp.first->data){
        
            if(ans.second != NULL){
                if(ans.second->data < temp.first->data)
                    ans.second = temp.first;
             
            }
            else
                ans.second = temp.first;
        }
        
        else{
            if(ans.second!=NULL){
                if(temp.second!=NULL){
                    if(temp.second>ans.second)
                        ans.second = temp.second;
                }
            }
            else{
                if(temp.second!=NULL){
                    ans.second = temp.second;
                }
            }
        }
        
    
    }
     return ans;
}

TreeNode <int>* secondLargest(TreeNode<int> *root) {
    pair<TreeNode<int>*, TreeNode<int>*> p = helperSL(root);
    return p.second;
}

int main() {

}
