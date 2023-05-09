#include <iostream>

using namespace std;

class Node{
public:
    char data;
    Node* next;
    int flag;
    Node() {

    }

    Node (char data) {
        this->data = data;
        this->next = NULL;
        this->flag = -1;

    }
};

class LL {
public:

    int size;
    Node *head;
    Node *tail;
    LL(){
        size = 0;
        head = NULL;
        tail = head;
    }

    void insert(char data) {
        Node *newnode = new Node(data);
        size++;
        if (head == NULL) {
            head = newnode;
            tail = newnode;
            return;
        }

        else {
            Node* temp_head = head;
            while (temp_head != NULL) {
                if (newnode->data == temp_head->data) {
                    temp_head->flag = 1;
                    return;
                }
                temp_head = temp_head->next;
            }
         
            tail->next = newnode;
            tail = tail->next;
        }
    }


    void remove_front(){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        size--;
    }

    void print() {
        Node * cur = head;
        while (cur != NULL) {
            cout << cur->data << " f=" << cur->flag << " ";
            cur = cur->next;
        }
    }

    char find() {
        Node* cur = head;
        while (cur != NULL) {
            if (cur->flag == -1) {
                return cur->data;
            }

            cur = cur->next;
        }

        return '$';
    }    
};



int main() {
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        LL l;
            
        for (int i = 0; i < n; i++) {
            char c; 
            cin >> c;
            l.insert(c);
            char res = l.find();
            if (res == '$') {
                cout << -1 << " ";
                // l.remove_front();
            }
            else {
                cout << res << " ";
            }
        }
        // l.print();
        
        cout << "\n";

    }


    
 
    return 0;
}