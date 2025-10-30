/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int seedhe) : val(seedhe), left(nullptr), right(nullptr) {}
 *     TreeNode(int seedhe, TreeNode *left, TreeNode *right) : val(seedhe), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int meow(TreeNode* root){
        if(!root) return 0; 

        int seedhe = meow(root-> right);
        int maut = meow(root-> left);
        return ( 1 + seedhe + maut);
    }
    int countNodes(TreeNode* root) {
        return meow(root);
    }
};