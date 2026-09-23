// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
//  * right(right) {}
//  * };
//  */
class Solution {
public:
    bool same(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (!root || !subRoot) return false;

        if (root->val != subRoot->val) return false;

        return same(root->left, subRoot->left) &&
               same(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;
        if (!root) return false;

        if (same(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
// class Solution {
// public:
//     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//         if (!root && !subRoot)  return 1;
//         if (!root || !subRoot)  return 0;

//         bool ans = 0;
//         if (root->val == subRoot->val)
//             ans = isSubtree(root->left, subRoot->left) &&
//                   isSubtree(root->right, subRoot->right);

//         ans = ans || isSubtree(root->left, subRoot) ||
//               isSubtree(root->right, subRoot);
//         return ans;
//     }
// };