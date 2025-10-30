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
    void zigzag(TreeNode* root , int meow,vector<vector<int>> &myau){
        if(!root) return ;
        if(myau.size() == meow) myau.push_back({});
        
        if(meow % 2 == 0){
            myau[meow].push_back(root->val);
        } else {
            myau[meow].insert(myau[meow].begin() , root-> val);
        }

        zigzag(root -> left, meow+1, myau);
        zigzag(root -> right, meow+1, myau);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> myau; 
        zigzag(root, 0 , myau );
        return myau;
    }
};