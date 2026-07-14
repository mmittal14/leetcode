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
    void level(TreeNode* root,int i, vector<vector<int>>& ans){
        if(root==nullptr){
            return;
        }
        if (ans.size() == i)
            ans.push_back({});
        ans[i].push_back(root->val);
        level(root->left,i+1,ans);
        level(root->right,i+1,ans);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int i=0;
        level(root,0,ans);
        return ans;
    }
};