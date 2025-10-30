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
    void level(TreeNode* root, int curlvl , vector<int> &ans){
        if(!root) return ;
        if(curlvl>=ans.size() ) ans.push_back(root->val);

        else ans[curlvl] += root-> val;

        level(root->left, curlvl +1, ans);
        level(root->right, curlvl +1, ans);
        

    }
    int maxLevelSum(TreeNode* root) {
        vector<int> ans;
        level(root, 0, ans);
    
        int maxsum = ans[0] , sol =1;
        for(int i=0;i<ans.size();i++){
            if(ans[i] > maxsum){
                maxsum = ans[i];
                sol = i+1;
            }
        }
        return sol;
    }
};