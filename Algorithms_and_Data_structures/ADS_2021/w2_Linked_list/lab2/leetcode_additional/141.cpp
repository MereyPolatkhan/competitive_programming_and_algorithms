class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast){
                return true;
            }
        }
        
        return false;
    }
};


class Solution {
public:
    map<ListNode*, bool> pam; 
    bool hasCycle(ListNode *head) {
        
        while(head != NULL){
            if (pam[head] == true){
                return true;
            }
            pam[head] = true;
            head = head->next;
        }

        return false;
    }
};

