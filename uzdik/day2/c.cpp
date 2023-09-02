#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

bool check(vector<int> &a) {
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] % 2 != a[i + 1] % 2) {
            return false;
        }
    }
    return true;
}
void solve() {
  
    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (i % 2 == 1) {
            a.pb(x);
        }
        else {
            b.pb(x);
        }
    }
    
    if (check(a) and check(b)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

/*  things to check:
    !  clear & resize SET, MAP, VECTOR, etc. or write in local functions
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
*/

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

