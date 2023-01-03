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
    
    bool isValidBST(TreeNode* root) {
        vector<int> in;
        inorder(root, in);
        vector<int> temp = in;
        sort(temp.begin(), temp.end());
        for(int i = 0; i < in.size(); i++) {
            if(in[i] != temp[i]) return false;
            if(i > 0 && temp[i] == temp[i - 1]) return false;
        }
        return true;
    }
    
    void inorder(TreeNode* root, vector<int>& in) {
        if(!root) return;
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
};