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
    ListNode *detectCycle(ListNode *head) {
        //  1 2 |3| 4 5 6 7 8 9
        if (head == NULL || head->next == NULL)
        return NULL;
    
        ListNode *slow  = head;
        ListNode *fast  = head;
        ListNode *entry = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {                      
                while(slow != entry) {
                    slow  = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;           
    }
};