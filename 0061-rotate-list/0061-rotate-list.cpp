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
    ListNode* rotateRight(ListNode* head, int k) {
        // 1 2 3 4 5  -->> 2 3 4 5 1 || 3 4 5 1 2
        int n=1;
        if(head==NULL || k==0) return head;
        ListNode *curr=head;
        while(curr->next!=NULL){
            // 1 2 3 4 5 //  2
            curr=curr->next;
            n++;
        }
        if(k>n){
            k=k%n;
        }
        curr->next=head;
        int len=n-k;
        for(int i=0;i<len;i++){
            curr=curr->next;
        }
        head=curr->next;
        curr->next=NULL;
        return head;
    } 
};