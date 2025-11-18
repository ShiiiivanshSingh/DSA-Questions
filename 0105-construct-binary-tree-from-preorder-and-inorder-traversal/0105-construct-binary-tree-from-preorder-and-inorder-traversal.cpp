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
int current = 0;
    TreeNode* solve(vector<int>& inorder , vector<int>& preorder , int start , int end ){
        if(start > end) return NULL;

    TreeNode* node = new TreeNode(preorder[current++]);
    if(start == end){

        return node;
    }
    int  i = start;
    while(i <= end && inorder[i]!= node->val){
        i++;
    }
    node->left = solve(inorder , preorder , start ,i -1);
    node->right = solve(inorder , preorder , i+1 ,end);
    
        return node;
    } 
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = inorder.size();

        return solve(inorder , preorder,  0 , size-1);
    }
};