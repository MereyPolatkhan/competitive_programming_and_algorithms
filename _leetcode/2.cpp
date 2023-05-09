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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        int s = 0;
        while (l1 != NULL and l2 != NULL) {
            int sum = l1->val + l2->val + s;
            int res = sum % 10;
            s = sum / 10;
            ListNode* newNode = new ListNode(res);
            cur->next = newNode;
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL) {
            int sum = l1->val + s;
            int res = sum % 10;
            s = sum / 10;
            ListNode* newNode = new ListNode(res);
            cur->next = newNode;
            cur = cur->next;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            int sum = l2->val + s;
            int res = sum % 10;
            s = sum / 10;
            ListNode* newNode = new ListNode(res);
            cur->next = newNode;
            cur = cur->next;
            l2 = l2->next;
        }
        if (s != 0) {
            cur->next = new ListNode(s);
        }
        return res->next;
    }
};