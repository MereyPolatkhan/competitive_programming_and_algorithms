#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node { 
    int data;
    int counter;
    Node *next;
    
    Node(int data) {
        this->data = data;
        this->counter = 0;
        this->next = NULL;
    }
};

struct LinkedList {
    
    Node *head;
    Node *tail;
    LinkedList() {
        this->head = NULL;
        this->tail = head;
    }

    void pushBack(int x) {
        if (head == NULL) {
            Node* newNode = new Node(x);
            newNode->counter = 1;
            head = newNode;
            tail = newNode;
            return;
        }
        
        Node* cur = head;
        while (cur != NULL) {
            if (cur->data == x) {
                cur->counter += 1;
                return;
            }
            cur = cur->next;
        }

        Node* newNode = new Node(x);
        newNode->counter = 1;
        tail->next = newNode;
        tail = tail->next;
    }

    void print() {
        Node* cur = head;
        while (cur != NULL) {
            cout << cur->data << " " << cur->counter << "\n";
            cur = cur->next;
        }
    }

    void solve() {
        vector<int> modes;
        
        int max_counted = 0;

        Node* cur = head;
        while (cur != NULL) {
            if (max_counted < cur->counter) {
                max_counted = cur->counter;
            }
            cur = cur->next;
        }

        Node* cur2 = head;
        while (cur2 != NULL) {
            if (cur2->counter == max_counted) {
                modes.push_back(cur2->data);
            }
            cur2 = cur2->next;
        }

        sort(modes.begin(), modes.end());
        
        reverse(modes.begin(), modes.end());
        

        for (int i = 0; i < modes.size(); i++) {
            cout << modes[i] << " ";
        }
    }

};

int main() {

    int n;
    cin >> n;

    LinkedList ll;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ll.pushBack(x);
    }

     ll.solve();
}