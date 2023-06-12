#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}


void solve() {

    int n;
    cin >> n;

    string s;
    cin >> s;


    unordered_set<int> st;
    st.insert(2);
    st.insert(3);
    st.insert(5);
    st.insert(7);

    for (int i = 0; i < n; i++) {
        int x = (int)s[i] - (int)'0';
        if (!st.count(x)) {
            cout << 1 << "\n" << x << "\n";
            return;
        }
    }



    for (int i = 0; i < n; i++) {
        int y = ((int)s[i] - (int)'0') * 10;

        for (int j = i + 1; j < n; j++) {
            int x = (int)s[j] - (int)'0';
            if (isPrime(x + y) == false) {
                cout << 2 << "\n" << x + y << "\n";
                return;
            }
        }
        

    }
    cout << s.substr(0, 2);
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}