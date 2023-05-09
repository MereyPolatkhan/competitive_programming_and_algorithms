#include <iostream>

using namespace std;

struct Node {
    int max_data;
    int data;
    Node* next;
    Node* prev;
    Node (int n) {
        data = n;
        max_data = n;
        next = NULL;
        prev = NULL;
    }
    Node(int n, int max_n) {
        data = n;
        max_data = max_n;
        next = NULL;
        prev = NULL;
        
    }
};

struct Stack {
    Node* head;
    Node* tail;
    int size;
    Stack() {
        size = 0;
        head = tail = NULL;
    }

    void add(int x) {
        size++;
        Node* n = new Node(x);
        if (head == NULL) {
            head = tail = n;
            return;
        }
        else {
            tail->next = n;
            n->prev = tail;
            tail = tail->next;
            tail->max_data = max(tail->max_data, tail->prev->max_data); 
        }
    }

    void pop(){
        if (head == NULL) {
            return;
        }
        else if (size == 1) {
            head = tail = NULL;
            size--;
            return;
        }

        else  {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
            size--;
            return;
        }
    }

    int top() {
        return tail->data;
    }

    int max_el(){
        return tail->max_data;
    }

};


int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    Stack st;
    while (n--) {
        string s;
        cin >> s;
        if (s == "add") {
            int x;
            cin >> x;
            st.add(x);
        }
        else if (s == "delete") {
            st.pop();
        }
        else if (s == "getcur") {
            if (st.size == 0) {
                cout << "error\n";
            }
            else cout << st.top() << "\n";
        }
        else if (s == "getmax") {
            if (st.size == 0) {
                cout << "error\n";
            }
            else cout << st.max_el() << "\n";
        }
    }


    return 0;
}