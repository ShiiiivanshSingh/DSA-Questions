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
    void inorder(TreeNode* root, vector<int> & myau){
        if(!root) return;
        inorder(root->left, myau);
        myau.push_back(root -> val);
        inorder(root->right, myau);


    }
    int minDiffInBST(TreeNode* root) {
        vector<int>  myau;
        int meow = INT_MAX;
        inorder(root, myau);
        for(int i =1 ; i< myau.size() ; i++){
            meow  = min(meow , myau[i] -  myau[ i -1]);
        }
        return meow;

    }
};