// https://leetcode.com/problems/implement-trie-prefix-tree/solution/

class Trie {
public:
    struct TrieNode {
        TrieNode* child[26];
        bool isLeafNode;
    };
    
    TrieNode* root; 
    
     TrieNode* getNode() {
        TrieNode* node = new TrieNode();
        for(int i = 0; i<26; i++) {
            node->child[i] = nullptr;
        }
        node->isLeafNode = false;
        return node;
    }
        
    Trie() {
        root = getNode();
    }
  
    // M is Word Length
    // Time : O(M) Space : O(M)
    void insert(string word) {
        if(search(word)) return;
        auto node = root;
        for(int i = 0; i<word.length(); i++) {
            int idx = word[i] - 'a';
            if(!node->child[idx]) {
                node->child[idx] = getNode();
            }
            node = node->child[idx];
        }
        node->isLeafNode = true;
    }
  
     // M is Word Length
    // Time : O(M) Space : O(1)
    bool search(string word) {
        auto node = root;
        if(!root) return false;
        for(int i = 0; i<word.length() && node; i++) {
            int idx = word[i]-'a';
            node = node->child[idx];
        }
        if(node) return node->isLeafNode;
        return false;
    }
  
     // M is Word Length
    // Time : O(M) Space : O(1)
    bool startsWith(string prefix) {
        auto node = root;
        if (!root) return false;
        for (int i = 0; i<prefix.length() && node; i++) {
            int idx = prefix[i] - 'a';
            node = node->child[idx];
        }
        return (node != NULL);
    }
};

