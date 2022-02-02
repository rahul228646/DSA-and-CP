// https://practice.geeksforgeeks.org/problems/single-valued-subtree/1/?problemStatus=unsolved&page=1&company[]=Media.net%20&query=problemStatusunsolvedpage1company[]Media.net

bool countSingleRec(Node* root, int &count)
{
    // Return false to indicate NULL
    if (root == NULL)
       return true;
 
    // Recursively count in left and right subtrees also
    bool left = countSingleRec(root->left, count);
    bool right = countSingleRec(root->right, count);
 
    // If any of the subtrees is not singly, then this
    // cannot be singly.
    if (left == false || right == false)
       return false;
 
    // If left subtree is singly and non-empty, but data
    // doesn't match
    if (root->left && root->data != root->left->data)
        return false;
 
    // Same for right subtree
    if (root->right && root->data != root->right->data)
        return false;
 
    // If none of the above conditions is true, then
    // tree rooted under root is single valued, increment
    // count and return true.
    count++;
    return true;
}
