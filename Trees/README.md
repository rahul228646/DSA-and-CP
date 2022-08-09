# Notes

### Binary Tree :

    Searching  : O(n)
    Insertion  : O(n)
    Deletion   : O(n)

### Binary Search Tree :

    Searching  : O(n) (worst case) O(h) (general)
    Insertion  : O(n) (worst case) O(h) (general)
    Deletion   : O(n) (worst case) O(h) (general)
    
    Inorder of Binary Search Tree is Sorted
    
### Balanced Binary Search Tree :

    Searching  : O(h) h = logn
    Insertion  : O(h) h = logn
    Deletion   : O(n) h = logn

### AVL/ Height Balanced Tree :    
    https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
    
    Searching  : O(logn)
    Insertion  : O(logn) 
    Deletion   : O(logn) 
    
    AVL tree is a self-balancing Binary Search Tree (BST) where the difference between heights of 
    left and right subtrees cannot be more than one for all nodes. 
    
    To make sure that the given tree remains AVL after every insertion, we must augment the standard BST 
    insert operation to perform some re-balancing.To do this we do
    Left Rotation 
    Right Rotation
    
    The AVL trees are more balanced compared to Red-Black Trees, but they may cause more rotations during insertion and deletion. 
    So if your application involves many frequent insertions and deletions, then Red Black trees should be preferred. 
    And if the insertions and deletions are less frequent and search is the more frequent operation, 
    then AVL tree should be preferred over Red Black Tree.
