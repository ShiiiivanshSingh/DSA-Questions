class Solution {
public:
    int ans = 0;

    int dfs(TreeNode* root) {
        if (!root) return INT_MIN;
        int t = max({
                root->val, 
                dfs(root->left), dfs(root->right)});
        ans += (root->val == t);
        return t;
    }

    int countDominantNodes(TreeNode* root) {
        ans = 0; dfs(root);
        return ans;
    }
};