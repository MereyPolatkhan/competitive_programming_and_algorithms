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
    ListNode* get_mid(ListNode* head) {
        ListNode* mid_prev = NULL;
        while (head != NULL && head->next != NULL) {
            if (mid_prev == NULL) {
                mid_prev = head;
            }
            else {
                mid_prev = mid_prev->next;
            }
            head = head->next->next;
        }
        ListNode* mid = mid_prev->next;
        mid_prev->next = NULL;
        return mid;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* mid = get_mid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy_node(10);
        ListNode* ptr = &dummy_node;

        while(left != NULL && right != NULL) {
            if (left->val < right->val) {
                ptr->next = left;
                left = left->next;
            }
            else {
                ptr->next = right;
                right = right->next;
            }
            ptr = ptr->next;
        }

        if (left != NULL) {
            ptr->next = left;
        } 
        else {
            ptr->next = right;
        }

        return dummy_node.next;
    }

};