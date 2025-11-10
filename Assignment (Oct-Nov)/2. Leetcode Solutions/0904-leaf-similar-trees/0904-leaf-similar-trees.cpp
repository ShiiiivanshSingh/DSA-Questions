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

    void populate(TreeNode* root, vector<int> &arr){
        if(!root) return;
        if(!root-> right && !root-> left) arr.push_back(root->val);

        populate(root->left, arr);
        populate(root->right, arr);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a;
        vector<int> b;

        populate(root1, a);
        populate(root2, b);

    if(a!=b)return 0;
    else return 1;

    }
};