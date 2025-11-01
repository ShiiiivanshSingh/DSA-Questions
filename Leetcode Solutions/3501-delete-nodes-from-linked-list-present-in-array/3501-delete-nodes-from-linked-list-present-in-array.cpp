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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>m;

        for(auto it:nums){
            m[it]=1;
        }

        while( head && m.find(head->val)!= m.end()) {
            head= head->next;
        }
        ListNode* temp=head;

        while(head && head->next ){

            if(m.find((head->next)->val) != m.end()){
                head->next=head->next->next; 
            }
            else{
                head=head->next;
            }
        }
        head=temp;
        return head;

    }
};