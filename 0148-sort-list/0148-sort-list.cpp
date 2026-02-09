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

 // find middle node
 // split 2 half
 // recr. sort
 // merge2sorted
class Solution {
public:
    ListNode* middle(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast && fast->next){
            slow =slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge2sorted(ListNode* a , ListNode* b){
        ListNode* final;
        if(!a) return b;
        if(!b) return a;
        if(a->val > b->val){
            final = b;
            final->next = merge2sorted(a  ,b->next);
        }   else {
            final = a;
            final->next = merge2sorted(a->next, b);
        }
        return final; 
    }
    ListNode* sortList(ListNode* head) {
       if(!head || !head->next) return head;
        
        ListNode* middle_pos = middle(head);
        ListNode* rightside = middle_pos->next;
            middle_pos->next = NULL;
        ListNode* a = sortList(rightside);
        ListNode* b = sortList(head);
        return merge2sorted(b,a);
    }
};