#include <bits/stdc++.h> 

using namespace std;


int main() {
    // freopen("input.txt", "r", stdin);
    deque<int> dek;

    char c;
    int x;
    while (true){
        cin >> c;
        if (c == '!') {
            // stop
            return 0;
        } 
        else if (c == '+') {
            cin >> x;
            // add begin
            dek.push_front(x);
        }
        else if (c == '-') {
            cin >> x;
            // add back
            dek.push_back(x);
        }
        else if (c == '*') {
            // check for empty or not
            if (dek.size() == 0) {
                cout << "error\n";
            } 
            else {
                //  sum of first and last elements and delete elements
                cout << dek.front() + dek.back() << "\n";
                if (dek.size() == 1) {
                    dek.pop_front();
                }    
                else {
                    dek.pop_front();
                    dek.pop_back();
                }
            }
        }
    }


    return 0;
}