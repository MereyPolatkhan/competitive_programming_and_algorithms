class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 0) edge case
        // if (head == NULL) return true;

        // 1) find mid (with Floyd's method)
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != NULL and fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // 2) reverse all node mid-end
        ListNode* right = reverse(slow);
        
        // 3) check with two pointers
        ListNode* left = head;

        while (left != NULL and right != NULL) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        
        return true;
    }

    ListNode* reverse(ListNode* node) {
        ListNode* dummy = NULL;
        ListNode* prev = dummy;
        ListNode* cur = node;

        while (cur != NULL) {
            ListNode* nxt_el = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt_el;
        }
        return prev;
    }
};