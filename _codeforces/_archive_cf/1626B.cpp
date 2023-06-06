#include <bits/stdc++.h>


using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    
    int index = -1;
    int x = -1;
    for (int i = 0; i < n - 1; i++) {
        x = (int)s[i] - 48 + (int)s[i + 1] - 48;
        if (x >= 10) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = 0; i < n; i++) {
            if (i == index) {
                cout << x;
            }
            else if (i == index + 1) {
                continue;
            }
            else {
                cout << s[i];
            }
        }
        cout << "\n";
        return;
    }

    cout << (int)s[0] + (int)s[0 + 1] - 96;
    for (int i = 2; i < n; i++) cout << s[i];
    cout << "\n";
  
}

int main() {
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