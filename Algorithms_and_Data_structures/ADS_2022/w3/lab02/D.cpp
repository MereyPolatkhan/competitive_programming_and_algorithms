#include <iostream>

using namespace std;

struct Node {
    int val;
    int cnt;
    Node *next;
    Node() {
        val = 0;
        cnt = 0;
        next = NULL;
    }
    Node (int val) {
        this->val = val;
        this->cnt += 1;
        this->next = NULL;
    }
};

struct LinkedList {
    Node* head;
    Node* tail;
    Node* modes;
    Node* modesTail;
    LinkedList() {
        this->head = NULL;
        this->tail = head;
        this->modes = NULL;
        this->modesTail = modes;
    }

    void insert(int val) {
        Node *newnode = new Node(val);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
            return;
        }

        else {
            Node* cur = head;
            while (cur != NULL) {
                if (cur->val == newnode->val) {
                    cur->cnt++;
                    return;
                }
                cur = cur->next;
            }
            tail->next = newnode;
            tail = tail->next;
        }
    }

    void collectModes() {
        Node* cur = head;
        int max_cnt = -1;
        while (cur != NULL)  {
            if (cur->cnt > max_cnt) {
                max_cnt = cur->cnt;
            }
            cur = cur->next;
        }
        func(max_cnt);
        sort_modes();
        Node* temp = modes;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        
    }

    void sort_modes() {
        Node* cur = modes;
        Node* nxt = NULL;
        while (cur->next != NULL) {
            nxt = cur->next;
            while (nxt != NULL) {
                if (cur->val < nxt->val){
                    swap(cur->val, nxt->val);
                }
                nxt = nxt->next;
            }
            cur = cur->next;
        }
    }

    void func(int max_cnt) {
        Node *cur = head;
        while (cur != NULL) {
            if (cur->cnt == max_cnt) {
                Node *newn = new Node(cur->val);
                if (modes == NULL) {
                    modes = newn;
                    modesTail = newn;
                }
                else {
                    modesTail->next = newn;
                    modesTail = modesTail->next;
                }
            }
            cur = cur->next;
        }
    }
};

int main() {    
    int n;
    cin >> n;
    LinkedList ll;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ll.insert(x);
    }     
    ll.collectModes();  

    return 0;
}