class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *dummy = NULL;

        ListNode *prev = dummy;
        ListNode *curr = head;

        while(curr != NULL) {
            ListNode *next = curr->next;
            
            curr->next = prev;
            prev = curr;
            curr = next;           
        }        

        return prev;
    }
};