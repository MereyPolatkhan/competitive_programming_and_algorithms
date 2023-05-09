class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0, head);
        
        ListNode *prev = dummy;
        ListNode *curr = head;
        
        while(curr != NULL) {
            if (curr->val != val) {
                prev = curr;
            }
            else {
                prev->next = curr->next;
            }
            curr = curr->next;
        }
        
        return dummy->next;
    }
};