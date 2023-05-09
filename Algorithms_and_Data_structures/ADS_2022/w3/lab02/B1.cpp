#include <iostream>

using namespace std;

struct Node {
    string data;
    Node * next;

    Node(string data) {
        this->data = data;
        this->next = NULL;
    }
};


struct LinkedList {
    Node* head;
    Node* tail;

    LinkedList() {
        head = NULL;
        tail = head;
    }

    void build(string data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        
        tail->next = newNode;
        tail = tail->next;
    }


    void shift(int k) {
        // 1 -> 2 -> NULL 3 -> 4 -> 5 -> NULL
        // k = 2;
        // head = 3 -> 4 -> 5 -> 1 -> 2 -> NULL;

        Node* cur = head; // cur сонгы элементти биринши элементке косу ушин
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = head;

        Node* cur2 = head;
        for (int i = 0; i < k - 1; i++) { // cur2 k-ши позициядагы элементтин алдындагы элементке бару ушин
                                            // 1 2 3 4 5 ; к=2
                                            // К-ши элемент бизде 3 (0-ден бастаганда)
            cur2 = cur2->next;
        }
        Node* newHead = cur2->next;
        cur2->next = NULL;
        head = newHead;
    }

    void print(){ 
        Node* cur = head;
        while (cur != NULL) {
            cout << cur->data << " ";
            cur = cur->next;
        }
    }
};



int main() {

    int n, k;
    cin >> n >> k;

    LinkedList ll;

    for (int i = 0; i < n; i++) {
        // build LL;
        string x;
        cin >> x;
        ll.build(x);
    }


    ll.shift(k);

    ll.print();


    return 0;
}