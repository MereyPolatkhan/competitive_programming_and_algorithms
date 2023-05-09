#include <iostream> 
#include <deque>

using namespace std;

int main() {

    deque <int> q;

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