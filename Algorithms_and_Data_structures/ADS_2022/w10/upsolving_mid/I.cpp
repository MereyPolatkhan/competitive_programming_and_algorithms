#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;

    stack<long long> st;
    vector<long long> a;

    while (n != 0) {
        a.push_back(n % 2);
        n /= 2;
    }

    reverse(a.begin(), a.end());

    for (long long i = 0; i < a.size(); i++){
        if (st.empty()) {
            st.push(a[i]);
        }
        else {
            if (st.top() == 1 && a[i] == 0) {
                st.pop();
            }
            else {
                st.push(a[i]);
            }
        }
    }

    if (st.empty()) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}