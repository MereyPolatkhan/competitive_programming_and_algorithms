#include <bits/stdc++.h> 

using namespace std;

int main() {

    string s;
    cin >> s;

    if (s.size() % 2 == 1) {
        cout << "NO";
        return 0;
    }

    stack<char> box;
    for (int i = 0; i < s.size(); i++) {
        if (box.size() == 0){ 
            box.push(s[i]);
        }
        else {
            char top = box.top();
            char current = s[i];
            if (top == current) {
                box.pop();
            }
            else {
                box.push(current);
            }
        }
    }

    if (box.size() == 0){
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;

}