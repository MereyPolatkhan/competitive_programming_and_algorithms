#include <bits/stdc++.h>

using namespace std;


int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> res(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        int index = i;
        while (st.size() > 0 && a[i] < a[st.top()]) {
            res[st.top()] = index;
            st.pop();

        }

        st.push(i);
    }

    for (int i : res) cout << i << " "; cout << "\n";

    return 0;
}