#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef pair<int, int> pii;

bool ch(int n, int x) {
    if (n % x == 0) {
        n = n / x;
        return (int)pow((int)sqrt(n), 2) == n;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;

    if (ch(n, 2) || ch(n, 4)) {
        cout << "YES\n";
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
