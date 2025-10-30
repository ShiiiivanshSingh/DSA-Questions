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
    void meow(TreeNode* root , int level, vector<vector<int>>& uwu){
        if(!root) return;
        if(level >= uwu.size()) uwu.push_back({});
        uwu[level].push_back(root-> val);
        meow(root->left, level+1, uwu);
        meow(root->right, level+1, uwu);
    }
    bool isEvenOddTree(TreeNode* root) {
        vector<vector<int>> uwu;

        meow(root, 0 , uwu);

        for(int i = 0 ;i< uwu.size(); i++){
            int prev = (i % 2 == 0 ? INT_MIN : INT_MAX);
            for(int j : uwu[i]){
                if(i% 2 ==0){ // even level
                    if(j% 2 == 0 || j<= prev) return 0;

                } else { // odd level
                    if(j% 2 == 1 || j>= prev) return 0;
                }
                prev = j;
            }
            
        }
        return 1;
    }
};