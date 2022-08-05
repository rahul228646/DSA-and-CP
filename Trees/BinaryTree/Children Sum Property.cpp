https://www.youtube.com/watch?v=fnmisPM6cVo&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=30

void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(!root) return;
    int child = 0;
    if(root->left) child += root->left->data;
    if(root->right) child += root->right->data;
    if(child>=root->data) root->data = child;
    else {
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    int sum = 0;
    if(root->left) sum += root->left->data;
    if(root->right) sum += root->right->data;
    if(root->left || root->right) root->data = sum; // if the node is leaf node then it could become zero without if statement
   
}  

while going down increase the value of children if their sum is less than root node
during backtracking make the root sum equal to sum of their children, except in case of leaft node as its children are null there fore we do not want to 
make the node value = 0
