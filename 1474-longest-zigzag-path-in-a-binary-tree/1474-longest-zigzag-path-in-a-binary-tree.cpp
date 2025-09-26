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
    int final = 0;
    void trav(TreeNode* root, int len, bool isLeft){
        if(!root) return;
        final = max(final , len);

        if(isLeft){
            trav(root->left , 1, 1);
            trav(root->right , len +1, 0);
        } else{
            trav(root->right ,1, 0);
            trav(root->left , len +1, 1);
        }

    }
public:
    int longestZigZag(TreeNode* root) {
        trav(root->left, 1 , 1);
        trav(root->right, 1, 0);
        
        return final;
    }
};