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

    vector<int> res;

    for (int i = 9; i >= 1; i--) { 
        if (n >= i) {
            res.pb(i);
            n -= i;
        }
    }

    if (n != 0) {
        cout << -1 << "\n";
    }
    else {
        sort(all(res));
        for (int i: res) cout << i;
        cout << "\n";
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
