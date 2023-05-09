#include <bits/stdc++.h>

using namespace std;
string s = "codeforces";
void solve() {
    char c;
    cin >> c;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}


int main() {
    int n;
    cin >> n;
    while (n--){
        solve();
    }

    return 0;
}