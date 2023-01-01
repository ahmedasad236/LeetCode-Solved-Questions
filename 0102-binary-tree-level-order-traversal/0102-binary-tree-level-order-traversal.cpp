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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            pair<TreeNode*, int> top = q.front();
            q.pop();
            if(top.second == res.size()) {
                vector<int> newLevel;
                newLevel.push_back(top.first->val);
                res.push_back(newLevel);
            } else {
                res[top.second].push_back(top.first->val);
            }
            
            if(top.first->left) q.push({top.first->left, top.second + 1});
            if(top.first->right) q.push({top.first->right, top.second + 1});
            
        }
        
        return res;
    }
};