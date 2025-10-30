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
    int meow(TreeNode* root){
        if(!root) return 0;

        int right  = meow(root-> right);
        if(right == -1) return -1;
        
        int left  = meow(root-> left);
        if( left == -1)   return -1;

        if(abs(left - right) > 1) return -1;

        return 1 + max(right, left);
    }
    bool isBalanced(TreeNode* root) {
        return meow(root) != -1;

    }
};