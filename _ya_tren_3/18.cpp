#include <bits/stdc++.h>

using namespace std;


int main() {
    // freopen("input.txt", "r", stdin);
    
    deque<int> q;

    string s;
    while (true) {
        cin >> s;
        if (s == "push_front") {
            int n;
            cin >> n;
            q.push_front(n);
            cout << "ok\n";
        }
        if (s == "push_back") {
            int n;
            cin >> n;
            q.push_back(n);
            cout << "ok\n";
        }

        if (s == "pop_front") {
            if (q.size() == 0) {
                cout << "error\n";
            }
            else {
                cout << q.front() << "\n";
                q.pop_front();
            }
        }
        if (s == "pop_back") {
            if (q.size() == 0) {
                cout << "error\n";
            }
            else {
                cout << q.back() << "\n";
                q.pop_back();
            }
        }
        if (s == "front") {
            if (q.size() == 0) {
                cout << "error\n";
            }
            else {
                cout << q.front() << "\n";
            }
        }
        if (s == "back") {
            if (q.size() == 0) {
                cout << "error\n";
            }
            else {
                cout << q.back() << "\n";
                // q.pop_back();
            }
        }
        if (s == "size") {
            cout << q.size() << "\n";
        }
        if (s == "clear") {
            while (q.size() > 0) {
                q.pop_back();
            }
            cout << "ok\n";
        }
        if (s == "exit") {
            cout << "bye\n";
            break;
        }
        
    }


    return 0;
}