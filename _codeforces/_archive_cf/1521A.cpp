#include <bits/stdc++.h>

using namespace std;

#define pb push_back
 
  
typedef long long ll;
typedef pair<int, int> pii;


void solve() {
    ll a, b, x, y, z;
    cin >> a >> b;
    if (b == 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << a << " " << a * b << " " << a * (b + 1) << "\n";
    

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

/*  things to check:
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
    4) clear
*/
