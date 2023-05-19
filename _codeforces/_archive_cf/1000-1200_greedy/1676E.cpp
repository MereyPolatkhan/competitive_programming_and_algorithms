#include <bits/stdc++.h>

using namespace std;

int bin(int x, vector<int> & a) {
    if (a.back() < x) {
        return -1;
    }
    if (x < a[0]) {
        return 1;
    }

    int l = 0;
    int r = a.size() - 1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (a[mid] == x) {
            return mid + 1;
        }
        else if (a[mid] < x) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }


    return l + 1;
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }
  
    while (q--) {
        int x;
        cin >> x;
        cout << bin(x, a) << "\n";
    }

}

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}