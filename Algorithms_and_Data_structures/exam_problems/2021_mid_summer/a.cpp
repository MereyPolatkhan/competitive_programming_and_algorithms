#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    cin >> s;

    if (s.size() % 2 == 1) {
        cout << "NO";
        return 0;
    }

    stack<char> st;

    for(int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        }

        else {
            if (st.size() > 0) {
                char current = s[i];
                char previous = st.top();
                if (current == ')' && previous == '(') {
                    st.pop();
                }
                else if (current == ']' && previous == '[') {
                    st.pop();
                }
                else if (current == '}' && previous == '{') {
                    st.pop();
                }
                else {
                    cout << "1NO";
                    return 0;
                }
            }
            else {
                cout << "2NO";
                return 0;
            }
        }
    }

    if (st.size() == 0){
        cout << "YES";
    }
    else {
        cout << "3NO";
    }
    return 0;

}