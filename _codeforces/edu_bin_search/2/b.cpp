#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int n, k;
vector<int> a;


bool check(double len) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += int(a[i] / len);
    }
    return cnt >= k;
}

void solve() {
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.pb(x);
    }

    double l = 0, r = 1e8;
    for (int y = 0; y < 100; y++) {
        double m = (l + r) * 0.5;
        if (check(m)) {
            l = m;
        }
        else {
            r = m;
        }
    }
    cout << setprecision(100) << l << "\n";
}

int main() {    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
