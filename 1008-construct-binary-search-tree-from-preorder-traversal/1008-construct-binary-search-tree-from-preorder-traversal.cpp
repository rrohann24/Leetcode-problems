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
    TreeNode* bstFromPreorderHelper(vector<int>& preorder, int l, int r){
        if(l>r){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[l]);
        int i;
        for(i=l+1; i<=r; i++){
            if(preorder[i]>root->val){
                break;
            }
        }
        
        root->left = bstFromPreorderHelper(preorder, l+1, i-1);
        root->right = bstFromPreorderHelper(preorder, i, r);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
           
          return bstFromPreorderHelper(preorder, 0, preorder.size()-1);
        
    }
};