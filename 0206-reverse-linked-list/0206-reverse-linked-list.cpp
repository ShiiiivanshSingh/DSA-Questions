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
    ListNode* reverseList(ListNode* head) {
        // ListNode *curr = head;
        // ListNode *prev = NULL;
        if(head == NULL|| head -> next ==NULL) return head;


        ListNode *new_head = reverseList(head -> next);

        head -> next -> next = head;
        head -> next = NULL;
        
        // ListNode *front = head->next;
        // front-> next = head;
        // head->next = NULL;
         return new_head;

    //     while(curr != NULL){
    //         prev = curr-> prev;
    //         curr -> val = head-> prev;
    //         curr -> next= head->prev ->val;
    // prev = curr->;
     }
 
};