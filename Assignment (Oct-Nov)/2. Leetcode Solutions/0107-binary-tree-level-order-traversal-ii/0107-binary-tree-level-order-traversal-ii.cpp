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

    void miaw(TreeNode* root , int meow, vector<vector<int>> &myau){
        if(!root) return ;
        if(myau.size() == meow) myau.push_back({});
        myau[meow].push_back(root-> val);

        miaw(root-> left, meow + 1, myau);
        miaw(root-> right, meow + 1, myau);

    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> myau; 
        miaw(root, 0 , myau);
        reverse(myau.begin(),myau.end());
        return myau;
    }
};