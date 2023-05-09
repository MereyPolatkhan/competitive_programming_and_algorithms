// time limit in 31 test case;
#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};

int size = 0;

Node* insert(Node* head, Node* node, int p){
    /* write your code here */
    if (head == NULL) {
        head = node;
        size = 1;
        return head;
    }
    else if (p == 0) {
        Node *temp = head;
        node->next = temp;
        head = node;
        size++;
        return head;
    } 
    else if (p == size){
        Node* cur = head;
        for (int i = 0; i < p-1; i++) {
            cur = cur->next;
        }
        cur->next = node;
        size++;
        return head;
    }
    else {
        Node* cur = head;
        for (int i = 0; i < p-1; i++) {
            cur = cur->next;
        }
        Node* temp = cur->next;
        cur->next = node;
        node->next = temp;
        size++;
        return head;
    }

}
 
Node* remove(Node* head, int p){
    /* write your code here */
    if (head == NULL) {
        cerr << "Empty LL\n";
        return head;
    }
    else if (p == 0) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        size--;
        return head;
    }

    else if (size - 1 == p) {
        Node* cur = head;
        for (int i = 0; i < p-1; i++) {
            cur = cur->next;
        }
        cur->next = NULL;
        size--;
        return head;
    }

    else {
        Node* cur = head;
        for (int i = 0; i < p-1; i++) {
            cur = cur->next;
        }
        Node* afterDeletingElement = cur->next->next;
        Node* deletingElement = cur->next;
        cur->next = afterDeletingElement;
        deletingElement->next = NULL;
        size--;
        return head;
    }
}
 
Node* replace(Node* head, int p1, int p2){
    /* write your code here */
    if (p1 == p2) {
        return head;
    }
    
    Node* cur = head;
    for (int i = 0; i < p1; i++) {
        cur = cur->next;
    }

    Node* newNode = new Node(cur->val);

    if (p1 < p2) {
        head = insert(head, newNode, p2+1); 
        head = remove(head, p1);
    } 
    else {
        head = insert(head, newNode, p2); 
        head = remove(head, p1+1);
    }
    return head;


}

Node* reverse(Node* head){
    /* write your code here */
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
 
void print(Node* head){
    /* write your code here */
    if (head == NULL) {
        cout << -1 << "\n";
        return;
    }
    Node* cur = head;
    while (cur != NULL) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << "\n";
}
 
Node* cyclic_left(Node* head, int x){
    /* write your code here */
    for (int i = 0; i < x; i++) {
        head = replace(head, 0, size - 1);
    }
    return head;
}
 
Node* cyclic_right(Node* head, int x){
    /* write your code here */
    for (int i = 0; i < x; i++) {
        head = replace(head, size - 1, 0);
    }
    return head;
}
 
int main(){
    // freopen("input.txt", "r", stdin);
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   

        else if (command == 777) {
            cout << "size = " << size << "\n";
        }
    
    
    }
    return 0;
}
