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
    ListNode* mid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
    return slow;
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if(!l1 ) return l2;
        if(!l2) return l1;
        ListNode* result;

        if(l1->val > l2->val){
            result = l2;
            result->next = merge(l1, l2->next);
        }   else {
            result = l1;
            result->next = merge(l1->next ,l2);
        }
    return result;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* middle= mid(head);
        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* x = sortList(right);
        ListNode* y =sortList(head);

        return merge(x ,y);
    }
};