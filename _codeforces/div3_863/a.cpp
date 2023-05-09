#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, d;
    cin >> n >> d;

    string s;
    cin >> s;

    int index = -1;

    for (int i = 0; i <= n - 1; i++) {
        if (int(s[i]) - int('0') < d) {
            index = i;
            break;
        }
    }

    for (int i = 0; i <= n - 1; i++) {
        if (i == index) {
            cout << d;
        }
        cout << s[i];
    }

    if (index == -1) {
        cout << d;
    }

    cout << "\n";

}

int main() {
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}