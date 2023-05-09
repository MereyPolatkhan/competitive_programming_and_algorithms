#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }

    int sum = a.back();

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--; r--;

        int changed_sum = (r - l + 1) * k;

        int actual_sum;
        if (l == 0) {
            actual_sum = a[r];
        }
        else {
            actual_sum = a[r] - a[l - 1];
        }

        if (actual_sum % 2 == 0) {
            if (changed_sum % 2 == 0) {
                if (sum % 2 == 0) {
                    cout << "NO\n";
                }
                else {
                    cout << "YES\n";
                }
            }
            else {
                if (sum % 2 == 0) {
                    cout << "YES\n";
                }
                else {
                    cout << "NO\n";
                }
            }
        }
        else {
            if (changed_sum % 2 == 0) {
                if (sum % 2 == 0) {
                    cout << "YES\n";
                }
                else {
                    cout << "NO\n";
                }
            }
            else {
                if (sum % 2 == 0) {
                    cout << "NO\n";
                }
                else {
                    cout << "YES\n";
                }
            }
        }
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }





    return 0;
}