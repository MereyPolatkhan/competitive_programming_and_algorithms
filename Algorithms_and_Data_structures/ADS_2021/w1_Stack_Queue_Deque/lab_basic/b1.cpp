#include <iostream>

using namespace std;

struct Queue{
    int a[100000];
    int st, en;

    Queue(){
        st = 0;
        en = 0;
    }

    int size(){
        return en - st;
    }

    int front(){
        return a[st];
    }

    int back(){
		return a[en-1];
    }

    bool empty(){
        return st == en;
    }

    void push(int x){
        a[en] = x;
        en++;
    }

    void pop() {
		st++;
    }

};

int main(){

	Queue q;

    string s;
    while(true){
        cin >> s;

        if (s == "push"){
            int a;
            cin >> a;
            q.push(a);
            cout << "ok\n";
        }

        if (s == "pop"){
            if (q.empty() == false){
                cout << q.front() << "\n";
                q.pop();
            }
            else {
                cout << "error\n";
            }
        }

        if (s == "front"){
            if (q.empty() == false){
                cout << q.front() << "\n";
            }   
            else {
                cout << "error\n";
            }
        }

        if (s == "size") {
            cout << q.size() << "\n";
        }

        if (s == "clear") {
            while(q.empty() == false){
                q.pop();
            }
            cout << "ok\n";
        }

        if (s == "exit"){
            cout << "bye\n";
            return 0;
        }
    }

    return 0;
}