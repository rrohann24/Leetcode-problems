/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(key>root->val){
            TreeNode* temp = deleteNode(root->right,key);
            root->right=temp;
        }
        else if(key<root->val){
            TreeNode* temp = deleteNode(root->left,key);
            root->left=temp;
        }
        else if(key==root->val){
            if(root->left==NULL&& root->right==NULL){
                delete root;
                return NULL;
            }
            
            //1 child
             if(root->left!=NULL && root->right==NULL){
                //left child is present
                 TreeNode* temp= root->left;
                 delete root;
                 return temp;
            }
            
            if(root->right!=NULL && root->left==NULL){
                //right child is present
                TreeNode* temp= root->right;
                delete root;
                return temp;
            }
            if(root->left!=NULL && root->right!=NULL){
            TreeNode* temp = root->left;
            //TreeNode* newLeft = temp;
            while(temp->right!=NULL && temp->right->right!=NULL){
                temp=temp->right;
            }
            int newRoot=temp->val;
            if(temp->right!=NULL) newRoot = temp->right->val;
            //temp->right=NULL;
            root->val = newRoot;
            //newR->right = root->right;
            root->left = deleteNode(root->left,newRoot);
            return root;
            }
        }
        return root;
    }
};