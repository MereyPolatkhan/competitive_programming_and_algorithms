#include <bits/stdc++.h>


using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> st;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        while (st.size() > 0 && st.top() > x) {
            st.pop();
        }

        if (st.size() > 0) {
            cout << st.top() << " ";
        }
        else {
            cout << -1 << " ";
        }

        st.push(x);
    }


    return 0;

}