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
          if(!head || !head->next) return head;
          ListNode *newH = reverseList(head->next);

          head->next->next = head;
          head->next= NULL;
          return newH;
    }


    
    bool isPalindrome(ListNode* head) {
    if(!head || !head->next) return 1;
    ListNode *slow= head;
    ListNode *fast = head;

    while(fast && fast->next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
     //slow is at centre now;
    ListNode *second = reverseList(slow);
    ListNode *first= head;
    ListNode *temp = second;

   while(second){
        if(first->val != second->val){
            reverseList(temp);
            return 0;
        }
            first = first->next;
            second = second-> next;
   }


    reverseList(temp);
    return 1;
    }
};