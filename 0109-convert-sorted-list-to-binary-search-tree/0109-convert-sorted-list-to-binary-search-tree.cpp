/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* ListToTree(vector<int>& meow,int left,int right){
        while(left > right) return NULL;
        int mid = (left+ right)/2;
        TreeNode* root=new TreeNode(meow[mid]);        
        root->left = ListToTree(meow, left, mid-1);
        root->right = ListToTree(meow,mid+1 , right);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> meow;
        while(head){
            meow.push_back(head-> val);
            head = head -> next;
        }
        return ListToTree(meow, 0 , meow.size() - 1);
    }
};