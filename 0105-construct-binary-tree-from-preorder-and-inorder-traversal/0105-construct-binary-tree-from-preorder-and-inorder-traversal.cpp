class Solution {
    int preIndex = 0;
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd) {
     
        if (inStart > inEnd) 
            return nullptr;
        
        
        TreeNode* node = new TreeNode(preorder[preIndex++]);
        
       
        if (inStart == inEnd)
            return node;
        
        
        int inIndex = inStart;
        while (inIndex <= inEnd && inorder[inIndex] != node->val) {
            inIndex++;
        }
        
      
        node->left = helper(preorder, inorder, inStart, inIndex - 1);
        node->right = helper(preorder, inorder, inIndex + 1, inEnd);
        
        return node;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIndex = 0;
        return helper(preorder, inorder, 0, inorder.size() - 1);
    }
};
