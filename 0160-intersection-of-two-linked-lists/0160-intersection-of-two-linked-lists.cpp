/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int count1=0,count2=0;
        ListNode *curr1=headA,*curr2=headB;
        while(curr1!=NULL){
            curr1=curr1->next;
            count1++;
        }
        while(curr2!=NULL){
            curr2=curr2->next;
            count2++;
        }
        int diff=count2-count1;
        if(diff<0){
            while(diff++ != 0){
                headA=headA->next;
            }
        }
        else{
             while(diff-- != 0){
                headB=headB->next;
            }
        }
        while(headA != NULL) {
            if(headA == headB) return headA;
            headB = headB->next;
            headA = headA->next;
        }
        return headA;
    }
};