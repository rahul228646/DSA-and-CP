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
    https://www.geeksforgeeks.org/avl-tree-set-2-deletion/
    
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
    
### Red Black Tree :
    
    Searching  : O(logn)
    Insertion  : O(logn) 
    Deletion   : O(logn) 
    
    A red-black tree is a kind of self-balancing binary search tree where each node has an extra bit, 
    and that bit is often interpreted as the color (red or black). 
    These colors are used to ensure that the tree remains balanced during insertions and deletions. 
    Although the balance of the tree is not perfect, it is good enough to reduce the searching time and maintain it 
    
    Rules That Every Red-Black Tree Follows: 
    1. Every node has a color either red or black. 1 bit is used to store color
    2. The root of the tree is always black.
    3. There are no two adjacent red nodes (A red node cannot have a red parent or red child).
    4. Every path from a node (including root) to any of its descendants NULL nodes has the same number of black nodes.
    5. All leaf nodes are black nodes.
    
    Height of a red-black tree with n nodes is h<= 2 log2(n + 1).
    https://www.geeksforgeeks.org/red-black-tree-set-2-insert/
