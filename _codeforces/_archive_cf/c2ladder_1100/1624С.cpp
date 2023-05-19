#include <bits/stdc++.h>


using namespace std;

void lower(int &x, int &n) {
    while (x > n) {
        x = x / 2;
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        lower(x, n);
        a[i] = x;
    }
    sort(a.begin(), a.end());
    // cout << "a[i]: ";
    // for (int i = 1; i <= n; i++) cout << a[i] << " ";
    // cout << "\n\n";

    vector<bool> used(n + 1, false);

    for (int i = n; i >= 1; i--) {
        int x = a[i];
        if (used[x] == false) {
            used[x] = true;
        }
        else {
            while (x > 0) {
                x = x / 2;
                if (used[x] == false) {
                    used[x] = true;
                    break;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (used[i] == false) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}