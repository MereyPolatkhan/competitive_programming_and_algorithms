#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    string pi = "314159265358979323846264338327";
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == pi[i]) cnt++;
        else break;
    }
    cout << cnt << "\n";

}

int main() {
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}