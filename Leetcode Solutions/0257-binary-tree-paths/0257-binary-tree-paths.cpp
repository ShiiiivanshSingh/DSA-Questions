//250 sawall ho gye i am getting cooked no cap on god ☆*: .｡. o(≧▽≦)o .｡.:*☆


/**
 * Definition for str binary tree node.
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

    vector<string> ans;

    void buh(TreeNode* root, string str){
        if(!root) return;
        if(!str.empty()) str += "->";

        str += to_string(root->val);

        if(!root->left && !root->right) {
            ans.push_back(str);
            return;
        } 

        buh(root->left, str);
        buh(root->right, str);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        buh(root , "");
        return ans;
        
    }
};