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
    int diameter   =0;
    int myau(TreeNode* root, int &diameter  ){
        if(!root) return 0;
        int let=  myau(root->left , diameter  );
        int rigt= myau(root->right , diameter  );

        diameter     = max(diameter   , let+ rigt);
        // cout << diameter   << " -> ";
        // cout << 1+ max(let, rigt) << "\n";
        return 1+ max(let, rigt);
    }


    int diameterOfBinaryTree(TreeNode* root) {
   
       myau(root, diameter  );
       return diameter;
    }
};