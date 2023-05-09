#include <bits/stdc++.h>
  
using namespace std;

struct Node{
	Node * prev;
	Node * next;
	string val;
	Node(string _val){
		prev = NULL;
		next = NULL;
		val = _val;
	}	
};

Node * head = NULL;
Node * tail = NULL;
int cnt;
void add_back(string s){
	cnt++;
    if (head == NULL) {
        Node * newnode = new Node(s);
		head = newnode;
		tail = newnode;
		return;
    }
	else {
        Node * newnode = new Node(s);
		tail->next = newnode;
		newnode->prev = tail;
		tail = tail->next;
	}
}
void add_front(string s){
	cnt++;
	if (head == NULL) {
        Node * newnode = new Node(s);
		head = newnode;
		tail = newnode;
		return;
	}
	else {
        Node * newnode = new Node(s);	
		head->prev = newnode;
		newnode->next = head;
		head = head->prev;
	}
}
bool empty(){
	return (cnt == 0);
}
void erase_front(){
	if (cnt == 0) {
		return;
	}
	else if (cnt == 1){ 
		head = tail = NULL;
		cnt--;
		return;
	}
	else {
		Node* temp = head;
		head = head->next;
		head->prev = NULL;
		delete temp;
		cnt--;
		return;
	}
}
void print(){
	Node * cur = head;
	while (cur != NULL) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << "\n";
}
void erase_back(){
	if (cnt == 0) {
		return;
	}
	else if (cnt == 1) {
		head = tail = NULL;
		cnt--;
		return;
	}
	else {
		Node* temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete temp;
		cnt--;
		return;
	}
}	
string front(){
	return head->val;
}
string back(){
	return tail->val;
}
void clear(){
	head = NULL;
	tail = NULL;
	cnt = 0;
	return;
}
  
int main()
{
	// freopen("input.txt", "r", stdin);
	string s;
   	while(cin >> s){
   		if(s == "add_front"){
   			string t;
   			cin >> t;
   			add_front(t);
   			cout << "ok" << endl;
   		}
   		if(s == "add_back"){
   			string t;
   			cin >> t;
   			add_back(t);
   			cout << "ok" << endl;
   		}
   		if(s == "erase_front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else
   			{
   				cout << front() << endl;
   				erase_front();
   			}
   		}
   		if(s == "erase_back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   				erase_back();
   			}
   		}
   		if(s == "front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << front() << endl;
   			}
   		}
   		if(s == "back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   			}
   		}
   		if(s == "clear"){
   			clear();
   			cout << "ok" << endl;
   		}
   		if(s == "exit"){
   			cout << "goodbye" << endl;
   			break;
   		}
		if (s == "p") {
			print();
		}
   		// cout << "hi" << endl;
   	}
    return 0;
}