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
// int level = 0;
    void solve(TreeNode* root, vector<vector<int>> &ans  , int level){
        if(!root) return ;
        // ans.push_back(root->val);
        if(ans.size()  == level) ans.push_back({});
        if(level % 2 == 0){
            ans[level].push_back(root->val);
        } else {
            ans[level].insert(ans[level].begin() , root->val);
        }
    solve(root->left , ans ,level +1  );
    solve(root->right ,ans , level +1 );


    } 
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root, ans , 0);
        return ans;
    }
};