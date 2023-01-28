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
    void deleteNode(ListNode* node) {
        if(node==NULL || node->next==NULL) {
            delete(node);
            return;
        }
        ListNode *curr=node->next;
        node->val=curr->val;
        node->next=curr->next;
        // delete(curr);
        return;
    }
};