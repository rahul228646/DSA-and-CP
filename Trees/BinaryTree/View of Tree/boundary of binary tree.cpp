class Solution {
public:
      
      void solveleft(Node* root, vector<int>&ans){
          
          if(root==NULL)
          return ;
          
          if(root->left==NULL && root->right==NULL)
          return ;
          
          ans.push_back(root->data);
          
          if(root->left)
          solveleft(root->left, ans);
          else solveleft(root->right, ans);
      }
      
      void leafleft(Node* root, vector<int>&ans){
          if(root==NULL)
          return ;
          
          if(root->left==NULL && root->right==NULL){
              ans.push_back(root->data);
              return ;
          }
          leafleft(root->left, ans);
          
          leafleft(root->right, ans);
          
      }
      
      void leafright(Node* root, vector<int>&ans){
          
          if(root==NULL)
          return;
          
          if(root->left==NULL && root->right==NULL){
              ans.push_back(root->data);
              return;
          }
          
          leafright(root->left, ans);
          
          leafright(root->right, ans);
          
      }
      
      void solveright(Node* root, vector<int>&ans){
          
          if(root==NULL)
          return ;
          if(root->left==NULL && root->right==NULL)
          return ;
          
          if(root->right)
          solveright(root->right, ans);
          else solveright(root->left, ans);
          
          
          ans.push_back(root->data);
      }
   vector <int> boundary(Node *root)
   {
       //Your code here
       
       vector<int>ans;
       
       if(root==NULL)
       return ans;
       
       ans.push_back(root->data);
       
       solveleft(root->left, ans);
       
       leafleft(root->left, ans);
       
       leafright(root->right, ans);
       
       solveright(root->right, ans);
       
       
       return ans;
       
       
       
       
   }
};
