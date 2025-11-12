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
// 3 in 1
// find middle eleement
// mereg 2 sorted lsit
// merge sort
//rec sorting 

// from -> leetcode.com/problems/middle-of-the-linked-list
// lc 876
    ListNode* mid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;  //for merge sort
    
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
// from -> leetcode.com/problems/merge-two-sorted-lists
// merge 2 sorted lists lc 21
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;

                
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1) {
            tail->next = list1;


        } else {
            tail->next = list2;
        }




        return dummy.next;
    }

// merge sort
    ListNode* sortList(ListNode* head) {
         if(!head || !head->next) return head;       
    
        ListNode* middle = mid(head);
        ListNode* right = middle->next;
        middle->next = NULL;

        ListNode* RIGHT = sortList(right);
        ListNode* LEFT = sortList(head);

        return merge(RIGHT, LEFT);
    
    }
};