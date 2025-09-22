/**
 * Definition for a binary tree root.
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
    int check(TreeNode* root,long long cur,int target,unordered_map<long long,int>& map){
        if(!root) return 0 ;
        cur += root->val;
        int ans = 0;
        if(map.count(cur - target)) ans +=map[cur - target];
        map[cur]++;

        ans += check(root->left, cur, target, map);
        ans += check(root->right, cur, target, map);

        map[cur]--; 
        return ans;   
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long ,int> map;
        map[0] =1;
        return check(root,0, targetSum, map);

    }
};