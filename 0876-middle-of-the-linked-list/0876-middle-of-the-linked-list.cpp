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
    ListNode* middleNode(ListNode* head) {
        ListNode *curr=head;
        ListNode *fast=head;
        if(head==NULL || head->next==NULL){
            return head;
        }
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            curr=curr->next;
        }
        // corner case for all even numbers
        if(fast->next!=NULL){
            return curr->next;
        }
        
        return curr;
    }
};