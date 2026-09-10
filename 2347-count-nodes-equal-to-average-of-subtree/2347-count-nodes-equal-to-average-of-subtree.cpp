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
    int occ = 0;

    pair<int,int> dfs(TreeNode* r) {
        if (!r) return {0, 0};
        pair<int,int> l = dfs(r->left);
        pair<int,int>  q = dfs( r->right);

        int sum = l.first + q.first  + r->val;
        int n = l.second + q.second + 1;

        if (r->val == sum / n) occ++;
        return {sum, n};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return occ;
    }
};