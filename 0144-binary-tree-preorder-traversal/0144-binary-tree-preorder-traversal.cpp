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
    void pre(TreeNode* node, vector<int>& path) {
        if(!node) return;
        path.push_back(node->val);
        pre(node->left, path);
        pre(node->right, path);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        pre(root, res);
        return res;
    }
};