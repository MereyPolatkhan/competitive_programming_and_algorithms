class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL and fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = NULL;
        while(slow != NULL) {
            ListNode *next_el = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next_el;
        }

        ListNode *left = head;
        ListNode *right = prev;
        
        while (right != NULL) {
            if (right->val != left->val) {
                return false;
            }
            right = right->next;
            left = left->next;
        }

        return true;
    }
};