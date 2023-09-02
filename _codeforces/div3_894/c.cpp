#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef pair<int, int> pii;


void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        int h = a[i];
        int cnt = 0;
        if (h > n) {
            cout << "NO\n";
            return;
        }
        // for (int j = 1; j <= h; j++) {
        //     if (a[j] >= i) {
        //         cnt++;
        //     }
        // }
        // if (h != cnt) {
        //     cout << "NO\n";
        //     return;
        // }

        if (a[h] >= i) {
            continue;
        }
        else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {   

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "----ans---\n";

    int t = 1;
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
