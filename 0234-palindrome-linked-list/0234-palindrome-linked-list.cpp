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
    
    ListNode *reverse(ListNode *head){
      ListNode *prev=NULL,*curr=head;
      while(curr!=NULL){
          ListNode *Next=curr->next;
          curr->next=prev;
          prev=curr;
          curr=Next;
      }
      return prev;
  }
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode *slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        // fast==NULL for even ll
        // fast!=NULL for odd  ll
        if(fast==NULL){
            slow=reverse(slow);
        }
        else{
            slow=reverse(slow->next);
        }
        fast=head;
        bool flag=false;
        while(slow->val==fast->val){
            if(slow->next==NULL){
                flag=true;
                break;
            }
            slow=slow->next;
            fast=fast->next;
        }
        if(flag) return true;
        return false;
    }
};