#include <iostream>

using namespace std;

struct Node {
    string val;
    int cnt;
    Node *next;
    Node() {
        this->val = "";
        this->cnt = 0;
        this->next = NULL;
    }
    Node (string val) {
        this->val = val;
        this->cnt += 1;
        this->next = NULL;
    }
};

int size = 0;

struct LinkedList {
    Node* head;
    Node* tail;

    LinkedList() {
        this->head = NULL;
        this->tail = head;
    }

    void insert(string val) {
        if (val == "" || val == "\n" || val == "\t") {
            return;
        }
        Node *newnode = new Node(val);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
            size ++;
            return;
        }
        else {
            if (tail->val == newnode->val) {
                tail->cnt++;
                return;
            }
            tail->next = newnode;
            tail = tail->next;

            size++;
            return;
        }
    }

    void print() {
        cout << "All in all: " << size << "\nStudents:\n";
        Node *cur = reverse();
        while(cur != NULL) {
            cout << cur->val << "\n";
            cur = cur->next;
        }
    }

    Node* reverse() {
        Node* dummy = NULL;
        Node* prev = dummy;
        Node* curr = head;

        while (curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;  
            prev = curr;
            curr = next;
        }
        return prev;
    }

};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    LinkedList l;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        l.insert(s);
    }

    l.print();
    return 0;
}