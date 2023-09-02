#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int n;

void funcAN() {
    for (int i = 1; i <= n + 1; i++)
        cout << i << " ";

    cout << "\n";
}

void funcA1() {
    cout << n + 1 << " ";
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }
    cout << "\n";
}


void func(vector<int> &a) {
    int j = -1;
    for (int i = 1; i <= n - 1; i++) {
        if (a[i] == 0 and a[i + 1] == 1) {
            j = i;
            break;
        }
    }
    if (j == -1) {
        cout << -1 << "\n";
    }
    else {
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
            if (i == j) {
                cout << n + 1 << " ";
            }
        }
        cout << "\n";
    }
}

void solve() {
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (a[n] == 0) {
        funcAN();
    }
    else if (a[1] == 1) {
        funcA1();
    }
    else {
        func(a);
    }
}

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

/*  things to check:
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
    4) clear
*/
