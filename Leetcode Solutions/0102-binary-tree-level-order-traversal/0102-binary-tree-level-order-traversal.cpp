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
//level order trav
    void levelOrder(TreeNode* root , int meow, vector<vector<int>> &myau){
        if(!root) return ;
        if(myau.size() == meow) myau.push_back({});
        myau[meow].push_back(root-> val);

        levelOrder(root-> left, meow + 1, myau);
        levelOrder(root-> right, meow + 1, myau);

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> myau; 
        levelOrder(root, 0 , myau);
        return myau;
    }
};