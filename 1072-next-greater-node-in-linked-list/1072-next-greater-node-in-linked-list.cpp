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
class Solution {
public:
    int c(ListNode* head) {
        int count = 0;
        while (head != NULL) {
            count++;
            head = head->next;
        }
        return count;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        int n = c(head);
        vector<int> ans(n, 0);
        stack<pair<int, int>> st;
        int idx = 0;
        ListNode* curr = head;
        while (curr) {
            while (!st.empty() && curr->val > st.top().second) {
                ans[st.top().first] = curr-> val;
                st.pop();
            }
            st.push({idx, curr->val});
            idx++;
            curr = curr->next;
        }
        return ans;
    }
};