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
    TreeNode* search(TreeNode* root, vector<int> &ans, int meow){
        if(!root) return nullptr;

        if(root->val == meow){
            ans.push_back(root->val);
            if(root->right) ans.push_back(root->right->val);
            if(root->left) ans.push_back(root->left->val);
            return root;
        }

        TreeNode* res = search(root->left, ans, meow);
        if(res) return res;

        return search(root->right, ans, meow);
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        vector<int> ans;
        return search(root, ans, val);
    }
};
