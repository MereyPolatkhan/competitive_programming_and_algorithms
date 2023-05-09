#include <bits/stdc++.h>

using namespace std;

void solve() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    char mx = s[0];
    for (int i = 0; i < n; i++) {
        mx = max(mx, s[i]);
    }

    cout << mx - 'a' + 1 << "\n";

}

int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }

    return 0;
}