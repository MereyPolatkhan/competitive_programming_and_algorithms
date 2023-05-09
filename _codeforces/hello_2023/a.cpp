#include <bits/stdc++.h>

using namespace std;

void solve() {  
    int n;
    cin >> n;

    string s;
    cin >> s;

    int r_index = -1;
    int l_index = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            r_index = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'L') {
            l_index = i;
            break;
        }
    }

    if (r_index == -1 || l_index == -1) {
        cout << -1 << "\n";
    }
    else {
        if (r_index < l_index) {
            cout << 0 << "\n";
        }
        else {
            if (r_index - l_index == 1) {
                cout << l_index + 1<< "\n";
            }
            else {
                cout << -1 << "\n";
            }
        }
    }
    // cout << l_index << " " << r_index;
}

int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
        solve();
    }



    return 0;
}