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
    void solve(TreeNode* root, vector<int> &values){
        if(root==NULL){
            return;
        }
        solve(root->left,values);
        values.push_back(root->val);
        solve(root->right,values);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        solve(root,ans);
        if(k<=ans.size()) return ans[k-1];
        return -1;
    }
};