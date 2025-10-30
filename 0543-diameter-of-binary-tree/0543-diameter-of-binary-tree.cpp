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
    int myau(TreeNode* root, int &ans){
        if(!root) return 0;
        int let=  myau(root->left , ans);
        int rigt= myau(root->right , ans);

        ans   = max(ans , let+ rigt);
        cout << ans << " -> ";
        cout << 1+ max(let, rigt) << "\n";
        return 1+ max(let, rigt);
    }


    int diameterOfBinaryTree(TreeNode* root) {
       int ans =0;
       myau(root, ans);
       return ans;
    }
};