#include <iostream>

using namespace std;

struct Deque{
    int a[100000];
    int st, en;

    Deque(){
        st = 49999;
        en = 49999;
    }

    void push_front(int x){
        st--;
        a[st] = x;
    }

    void push_back(int x){
        a[en] = x;
        en++;
    }

    void pop_front(){
        st++;
    } 

    void pop_back(){
        en--;
    } 

    int front(){
        return a[st];
    }

    int back(){
        return a[en-1];
    } 

    int size(){
        return en - st;
    }

    bool empty(){
        return (en == st);
    }

    // void show(){
    //     for (int i = st; i < en; i++){
    //         cout << a[i] << " ";
    //     }
    //     cout << "\n";
    // } 

};


int main() {

    Deque q;
  
    string s;

    while(true){    
        cin >> s;

        if (s == "push_front") {
            int x; cin >> x;
            q.push_front(x);
            cout << "ok\n";
        }

        if (s == "push_back") {
            int x; cin >> x;
            q.push_back(x);
            cout << "ok\n";
        }

        if (s == "pop_front") {
            if(q.empty() == false){
                cout << q.front() << endl;
                q.pop_front();
            }
            else {
                cout << "error\n";
            }
        }

        if (s == "pop_back") {
            if(q.empty() == false){
                cout << q.back() << endl;
                q.pop_back();
            }
            else {
                cout << "error\n";
            }
        }

        if (s == "front") {
            if (q.empty() == false){
                cout << q.front() << endl;
            }
            else {
                cout << "error\n";
            }
        }

        if (s == "back") {
            if (q.empty() == false){
                cout << q.back() << endl;
            }
            else {
                cout << "error\n";
            }
        }    

        if (s == "size") {
            cout << q.size() << endl;
        }   

        if (s == "clear") {
            while(q.empty() == false) {
                q.pop_front();
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