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
    vector<int> fcb;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        fcb.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* meow(int left, int right){ // builder
        if(left>right) return NULL;
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(fcb[mid]);

        node->left = meow(left,mid - 1);
        node->right = meow(mid + 1, right);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return meow(0 , fcb.size() - 1);
    }
};