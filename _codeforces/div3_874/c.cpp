#include <bits/stdc++.h>

using namespace std;
  
typedef long long ll;
typedef pair<int, int> pii;

int n;
bool func1(vector<int> a, int minka) {
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            a[i] -= minka;
        }
    }

    for (int i: a) {
        if (i > 0 and i % 2 == 0) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}

bool func2(vector<int> a, int minka) {
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            a[i] -= minka;
        }
    }
    


    for (int i: a) {
        if (i > 0 and i % 2 == 1) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int min_odd = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1 and a[i] < min_odd) {
            min_odd = a[i];
        }
    }

    if (min_odd == INT_MAX) {
        cout << "YES\n";
        return;
    }

    bool f1 = func1(a, min_odd);
    bool f2 = func2(a, min_odd);

    if (f1 == true || f2 == true) {
        cout << "YES\n";
        // cout << f1 << " " << f2 << "\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {    
    // freopen("input.txt", "r", stdin);
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

/*  things to check:
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
    4) clear
*/
