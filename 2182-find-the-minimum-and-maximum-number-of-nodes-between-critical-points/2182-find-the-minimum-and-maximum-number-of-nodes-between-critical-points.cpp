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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1, last = -1, mn = INT_MAX, i = 1;
        ListNode *a = head, *b = head->next;

        while (b->next) {
            if ((b->val > a->val && b->val > b->next->val) ||
                (b->val < a->val && b->val < b->next->val)) {
                
                if (first == -1) first = i;
                else mn = min(mn, i - last);
                last = i;
            }

            i++;
            a = b;
            b = b->next;
        }

        if (first == last) return {-1, -1};
        return {mn, last - first};
    }
};