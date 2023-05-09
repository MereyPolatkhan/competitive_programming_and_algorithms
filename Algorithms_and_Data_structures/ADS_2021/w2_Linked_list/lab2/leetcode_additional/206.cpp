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


class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *new_node = head;

        if (head->next != NULL) {
            new_node = reverseList(head->next);
            head->next->next = head;
        }
        head->next = NULL;
        return new_node;
    }
};