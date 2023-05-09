#include <bits/stdc++.h>

using namespace std;

void solve() {

    int n, l, r;
    cin >> n >> l >> r;

    string s;
    cin >> s;

    int cap = 0;
    int rab = 0;
    int uni = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            cap++;
        }
        else if (s[i] == '2') {
            rab++;
        }
        else if (s[i] == '3') {
            uni++;
        } 
    }

    for (int i = 0; i <= uni; i++) {
        int rabtar = (rab + uni - i);
        int kapitandar = cap + i;
        if (kapitandar == 0) {
            continue;
        }
        if (rabtar % kapitandar == 0) {
            int x = rabtar / kapitandar;
            if (l <= x + 1 and x + 1 <= r) {
                cout << "YES\n";
                return;
            }
        }
        else {
            int x = rabtar / kapitandar;
            if (l <= x + 1 and x + 2 <= r) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";

}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }




    return 0;
}