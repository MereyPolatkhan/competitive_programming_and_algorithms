// 100% 27/27
#include <iostream> 
#include <queue> 

using namespace std;

int main() {

    queue <int> q;

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
            if (q.size() > 0){
                cout << q.front() << "\n";
                q.pop();
            }
            else {
                cout << "error\n";
            }
        }

        if (s == "front"){
            if (q.size() > 0){
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