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
    bool miaw(TreeNode* r,TreeNode* l){
        if(!r && !l) return 1;
        if(!r || !l) return 0;
        return (r-> val == l-> val) && miaw(r->right,l->left) && miaw(r->left,l->right); 
    }
    bool isSymmetric(TreeNode* root) {
    if(!root) return 1;
        return miaw(root->left, root->right);
    }
};