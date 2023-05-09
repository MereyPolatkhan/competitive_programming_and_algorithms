class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(1e9);
        ListNode* cur = head;

        while (list1 != NULL and list2 != NULL) {
            if (list1->val < list2->val) {
                ListNode* temp = list1;
                list1 = list1->next;
                cur->next = temp;
            }
            else {
                ListNode* temp = list2;
                list2 = list2->next;
                cur->next = temp;
            }
            cur = cur->next;
        }

        while (list1 != NULL) {
            ListNode* temp = list1;
            list1 = list1->next;
            cur->next = temp;
            cur = cur->next;
        }

        while (list2 != NULL) {
            ListNode* temp = list2;
            list2 = list2->next;
            cur->next = temp;
            cur = cur->next;
        }
        return head->next;
    }
};