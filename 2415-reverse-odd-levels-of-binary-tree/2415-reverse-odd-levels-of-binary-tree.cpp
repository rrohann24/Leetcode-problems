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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> qu;
        vector<int> values;
        qu.push(root);
        int lev=0;
        while(!qu.empty()){
            int n = qu.size();
            vector<int> temp;
            for(int i=0; i<n; i++){
                TreeNode* node = qu.front();
                qu.pop();
                if(lev%2){
                    node->val = values[n-i-1];
                }
                if(node->left){
                    qu.push(node->left);
                    temp.push_back(node->left->val);
                }
                if(node->right){
                    qu.push(node->right);
                    temp.push_back(node->right->val);
                }
            }
            values=temp;
            lev++;
        }
        return root;
        /*if(!root) return root;
        
        queue<TreeNode*> q;
        vector<int> values;
        q.push(root);
        int level=0;
        
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> temp;
            for(int i=0; i<sz; i++)
            {
                TreeNode* node = q.front(); q.pop();
                
                if(level%2)
                    node->val = values[sz-i-1];
                
                if(node->left)
                {
                    q.push(node->left);
                    temp.push_back(node->left->val);
                }
                if(node->right) 
                {
                    q.push(node->right);
                    temp.push_back(node->right->val);
                }
                
            }
            values = temp;
            level++;
        }
        return root;*/
    }
};