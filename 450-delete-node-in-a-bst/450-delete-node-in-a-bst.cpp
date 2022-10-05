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
        if(key<root->val){
            root->left = deleteNode(root->left,key);
            return root;
        }
        if(key>root->val){
            root->right = deleteNode(root->right,key);
            return root;
        }
        if(key==root->val){
            if(root->right==NULL){
                return root->left;
            }
            else if(root->left==NULL){
                return root->right;
            }
            else{
                TreeNode* newR = root->right;
                while(newR->left!=NULL){
                    newR=newR->left;
                }
                root->val = newR->val;
                root->right = deleteNode(root->right,newR->val);
            }
        }
        return root;
    }
};