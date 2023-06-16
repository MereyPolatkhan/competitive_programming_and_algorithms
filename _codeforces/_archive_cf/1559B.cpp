#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;


    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (s[i] != '?') {
            flag = true;
        }
    }

    if (!flag) {
        for (int i = 0; i < n; i+=2) {
            s[i] = 'B';
        }
        for (int i = 1; i < n; i+=2) {
            s[i] = 'R';
        }
        cout << s << "\n";
        return;
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (s[i] != '?') {
                if (i - 1 >= 0 and s[i - 1] == '?') {
                    if (s[i] == 'R') {
                        s[i - 1] = 'B';
                    }
                    else {
                        s[i - 1] = 'R';
                    }
                }
                if (i + 1 < n and s[i + 1] == '?') {
                    if (s[i] == 'R') {
                        s[i + 1] = 'B';
                    }
                    else {
                        s[i + 1] = 'R';
                    }
                }
            }
        }
    }

    cout << s << "\n";
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout << "\n-----------RESULTS---------\n";
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}