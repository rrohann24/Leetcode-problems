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
    typedef long long ll;
    ll cnt=0;
    void solve(TreeNode* root, ll tar){
        if(root==NULL){
            return;
        }
        if(tar==root->val){
            cnt++;
        }
        
        solve(root->left,tar-root->val);
        solve(root->right,tar-root->val);
        //return leftAns+rightAns;
    }
    
    int pathSum(TreeNode* root, int tar) {
        if(root==NULL){
            return 0;
        }
        solve(root,tar);
        pathSum(root->left,tar);
        pathSum(root->right,tar);
        return cnt;
    }
};