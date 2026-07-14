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
    vector<int> postorderTraversal(TreeNode* root) {
        //post order is left->right->root
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        stack<TreeNode*> st1,st2;
        TreeNode* node=root;
        st1.push(node);
        while(!st1.empty()){
            node=st1.top();
            st1.pop();
            st2.push(node);
            if(node->left!=nullptr){
                st1.push(node->left);
            }
            if(node->right!=nullptr){
                st1.push(node->right);
            }
        }
        while(!st2.empty()){
            node=st2.top();
            st2.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};