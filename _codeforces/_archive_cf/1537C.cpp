#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

void print(vector<int>& a) {
    cout << " ==> ";
    for (int &i: a) cout << i << " ";
    cout << "\n\n";
}

int test_cast = 0;

void solve() {
    // cout << "\n\ntest_case: " << ++test_cast << "\n";
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a));

    int f = 0, s = 1;

    for (int i = 1; i < n - 1; i++) {
        if (a[s] - a[f] > a[i + 1] - a[i]) {
            s = i + 1;
            f = i;
        }
    }


    vector<int> b;
    for (int i = 0; i < n; i++) {
        if (i != f and i != s) {
            b.pb(a[i]);
        }
    }
    sort(all(b));

    cout << a[f] << " ";
    if (b.size() == 0) {
        cout << "";
    }
    else if (a[f] <= b[0] or b[b.size() - 1] <= a[s]) {
        for (int &j: b) cout << j << " ";
    }
    else {
        int j = 0;
        for (int i = 0; i < b.size(); i++) {
            if (a[i] >= a[f]) {
                j = i;
                break;
            }
        }

        for (int i = j; i < b.size(); i++) {
            cout << b[i] << " ";
        }
        for (int i = 0; i < j; i++) {
            cout << b[i] << " ";
        }
    }

    cout << a[s] << "\n";

    
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
