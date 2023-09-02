#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

void solve() {

    int n, a, b, s;

    cin >> n >> a >> b >> s;

    if (n == 1) {
        if (a == b and a == s)  {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
        return;
    }

    s -= a;
    s -= b;
    n -= 2;
    if (a * n <= s and s <= b * n ) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

}


int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}