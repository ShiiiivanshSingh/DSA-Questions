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
    void meow(TreeNode* root, vector<int>  &sol , int level ) {
        if(!root) return ; 

        if(level == sol.size()) sol.push_back(root->val);

        meow(root->right, sol , level +1);
        meow(root->left, sol , level +1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> sol;
        meow(root , sol , 0);
        return sol;
    }
};