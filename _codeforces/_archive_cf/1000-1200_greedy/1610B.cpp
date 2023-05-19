#include <bits/stdc++.h>

using namespace std;

bool func(vector<int> a, int i, int j, int x) {
    while (i < j) {
        if (a[i] == a[j]) {
            i++;
            j--;
        }
        else {
            if (a[i] == x) {
                i++;
            }
            else if (a[j] == x) {
                j--;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int i = 1;
    int j = n;
    while (i < j) {
        if (a[i] == a[j]) {
            i++;
            j--;
        }
        else {
            bool fi = func(a, i, j, a[i]);
            bool fj = func(a, i, j, a[j]);
            if (fi or fj) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    
    // freopen("input.txt", "r", stdin);

    long long t;
    cin >> t;

    while (t--)
        solve();


    return 0;
}