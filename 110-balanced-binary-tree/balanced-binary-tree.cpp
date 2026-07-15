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
    int compute(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int left=compute(root->left);
        int right=compute(root->right);
        if(left==-1 || right==-1){
            return -1;
        }
        if((left-right)>1 || (right-left)>1){
            return -1;
        }
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        int height=compute(root);
        if(height==-1){
            return false;
        }
        return true;
    }
};