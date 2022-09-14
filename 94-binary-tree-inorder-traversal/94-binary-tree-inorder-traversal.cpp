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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        stack<pair<TreeNode*,int>> st;
        vector<int> in;
        st.push({root,1});
        while(!st.empty()){
            auto it = st.top();
            TreeNode* node = it.first;
            int num=it.second;
            st.pop();
            if(num==1){
                it.second++;
                st.push(it);
                if(node->left) st.push({it.first->left,1});
            }
            if(num==2){
                in.push_back(it.first->val);
                it.second++;
                st.push(it);
                if(node->right) st.push({it.first->right,1});
            }
            
        }
        return in;
    }
};