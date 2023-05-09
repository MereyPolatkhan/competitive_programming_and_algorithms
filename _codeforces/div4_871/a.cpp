#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s = "codeforces";
    string n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n.size(); i++) {
        if (s[i] != n[i]) {
            cnt++;
        }
    }
    cout << cnt << "\n";
}

int main() {

    int t;
    cin >> t;
    while (t--){ 
        solve();
    }



    return 0;
}