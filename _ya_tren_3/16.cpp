#include <bits/stdc++.h>

using namespace std;


int main() {
    // freopen("input.txt", "r", stdin);

    string s;
    queue<int> q;
    while (true) {
        cin >> s;
        if (s == "push") {
            int n;
            cin >> n;
            q.push(n);
            cout << "ok\n";

        }
        else if (s == "pop") {
            if (q.size() == 0) cout << "error\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (s == "front") {
            if (q.size() == 0) cout << "error\n";
            else cout << q.front() << "\n";
        }
        else if (s == "size") {
            cout << q.size() << "\n";
        }
        else if (s == "clear") {
            while (q.size() > 0) {
                q.pop();
            }
            cout << "ok\n";
        }
        else if (s == "exit") {
            cout << "bye\n";
            break;
        }
        
    }



    return 0;
}