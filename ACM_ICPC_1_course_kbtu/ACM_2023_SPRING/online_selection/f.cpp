#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s = "";
    for (int i = 0; i < n; i++) {
        s += (char)((int)'a' + (i % k));
    }

    cout << s << "\n";
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}