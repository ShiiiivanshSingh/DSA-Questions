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
    int compare(TreeNode* &root, int value){
        if(!root) return 0;
        int count  = 0;

        if(root-> val >= value) count  =1;

        value= max(root->val , value);

        count += compare(root->left, value);
        count += compare(root->right, value);
        return count;
    }
    int goodNodes(TreeNode* root) {
        

        return compare(root, root->val);
        
    }
};