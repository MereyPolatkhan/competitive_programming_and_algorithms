#include <iostream>
#include <stack> 

using namespace std;

stack<char> clean(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '#') {
            st.push(s[i]);
        }
        else {
            st.pop();
        }
    }  
    return st;
}

int main() {

    string s, t;
    cin >> s >> t;

    stack<char> ss = clean(s);
    stack<char> tt = clean(t);

    if (ss != tt) {
        cout << "No";
    }
    else {
        cout << "Yes";
    }

    return 0;
}