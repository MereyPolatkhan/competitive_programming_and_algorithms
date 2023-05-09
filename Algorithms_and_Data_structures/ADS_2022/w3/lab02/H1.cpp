// OK accepted
// faster

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
    if (head == NULL) {
        head = node;
    }
    else if(p == 0) {
        node->next = head;
        head = node;
    }
    else {
        Node* cur = head;
        for (int i = 0; i < p - 1; i++) {
            cur = cur->next;
        }

        if (p == size) {
            cur->next = node;
        }
        
        else {
            Node* temp_need = cur->next;
            cur->next = node;
            node->next = temp_need;
        }
    }
    size++;
    return head;
}
 
Node* remove(Node* head, int p){
    if (head == NULL) {
        cout << "Empty LL\n";
        return head;
    }
    else if (p == 0){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    else {
        Node* cur = head;
        for (int i = 0; i < p - 1; i++) {
            cur = cur->next;
        }
        if (p == size - 1) {
            Node* temp = cur->next;
            cur->next = NULL;
            delete temp;
        }
        else {
            Node* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }
    }

    size--;
    return head;
}
 
Node* replace(Node* head, int p1, int p2){
    if (p1 == p2) {
        return head;
    }

    Node* cur = head;
    for (int i = 0; i < p1; i++) {
        cur = cur->next;
    }

    Node* newnode = new Node(cur->val);

    if (p1 < p2) {
        head = insert(head, newnode, p2 + 1);
        head = remove(head, p1);
    }
    else {
        head = insert(head, newnode, p2);   
        head = remove(head, p1 + 1);
    }

    return head;
}
 
Node* reverse(Node* head){
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
    if (x == 0) {
        return head;
    }
    Node* head_copy = head;
    Node* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = head;
    for (int i = 0; i < x - 1; i++) {
        head_copy = head_copy->next;
    }
    Node* temp = head_copy->next;
    head_copy->next = NULL;
    return temp;
}
 
Node* cyclic_right(Node* head, int x){
    if (x == 0) {
        return head;
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;
    
    Node* cur = head;
    for (int i = 0; i < size - x - 1; i++){
        cur = cur->next;
    }

    Node* newHead = cur->next;

    cur->next = NULL;
    
    return newHead;
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
    }
    return 0;
}