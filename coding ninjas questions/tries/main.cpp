#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
    public :
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this -> data = data;
        children = new TrieNode*[26];
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;
    
    public :
    
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertWord(TrieNode *root, string word) {
        // Base case
        if(word.size() == 0) {
            root -> isTerminal = true;
            return;
        }
        
        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }
        
        // Recursive call
        insertWord(child, word.substr(1));
    }
    
    // For user
    void insertWord(string word) {
        insertWord(root, word);
    }
    
    void removeWord(TrieNode *root, string word) {
        // Base case
        if(word.size() == 0) {
            root -> isTerminal = false;
            return;
        }

        // Small calculation
        TrieNode *child;
        int index =  word[0] - 'a';
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            // Word not found
            return;
        }

        removeWord(child, word.substr(1));

        // Remove child Node if it is useless
        if(child -> isTerminal == false) {
            for(int i = 0; i < 26; i++) {
                if(child -> children[i] != NULL) {
                    return;
                }
            }
            delete child;
            root -> children[index] = NULL;
        }
    }

    void removeWord(string word) {
        removeWord(root, word);
    }

    
    bool search(TrieNode *root, string word) {
        if(word.size() == 0){
            return root->isTerminal;
        }
        
        int index = word[0] - 'a';
        if(root->children[index] == NULL)
            return false;
        else
            return search(root->children[index], word.substr(1));
    }
    
    bool search(string word) {
        return search(root, word);
    }
    
    bool searchPattern(TrieNode *root, string word) {
        // Write your code here
        if(word.size() == 0){
            return true;
        }
        
        int index = word[0] - 'a';
        if(root->children[index] == NULL){
            return false;
        }
        else{
            return search(root->children[index], word.substr(1));
        }
        
    }
    
    bool searchPattern(string word) {
        return search(root, word);
    }

    bool patternMatching(vector<string> vect, string pattern) {
        // Complete this function
        // Return true or false
        
        for(int i=0; i<vect.size(); i++){
            string s = vect[i];
            for(int j=0; j<s.length(); j++){
                insertWord(root, s.substr(j));
            }
        }
        
        return searchPattern(pattern);

    }
    
    bool findIfPalindromePair(vector<string> vect) {
         
         bool val = true;
         for(int i=0; i<vect.size(); i++){
               string s = vect[i];
               for(int j=0; j<s.length(); j++){
                   insertWord(root, s.substr(j));
               }
           }
         
           for(int i=0; i<vect.size(); i++){
               string s = vect[i];
               for(int j=0,k=(int)s.length()-1; j<s.length()/2; j++,k--){
                   char temp = s[j];
                   s[j] = s[k];
                   s[k] = temp;
               }
               val = searchPattern(s);
                if(val)
                   return val;
           }
         return val;
     }
};

int main() {
    int choice;
    cin >> choice;
    Trie t;

    //cout << "asasas";
    while(choice != -1){
        string word;
        bool ans;
        switch(choice) {
            case 1 : // insert
                // getline(cin, word);
                cin >> word;
                t.insertWord(word);
                break;
            case 2 : // search
                // getline(cin, word);
                cin >> word;
                ans = t.search(word);
                if (ans) {
                    cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                }
                break;
            default :
                return 0;
        }
        cin >> choice;
    }
    return 0;
}

