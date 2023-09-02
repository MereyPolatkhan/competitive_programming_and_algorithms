#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;


void solve() {
    int n;
    cin >> n;

    int minX = 1e9, maxX = -1e9, minY = 1e9, maxY = -1e9;

    for (int i = 0; i < n; i++) {
        int ax, ay, bx, by, cx, cy, dx, dy;
        cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
        minX = min(minX, min(min(ax, bx), min(cx, dx)));
        maxX = max(maxX, max(max(ax, bx), max(cx, dx)));

        minY = min(minY, min(min(ay, by), min(cy, dy)));
        maxY = max(maxY, max(max(ay, by), max(cy, dy)));
        
    }

    // cout << minX << " " << maxX << " " << minY << " " << maxY<< "\n";
    

    cout << (ll) abs(maxY - minY) * (ll) abs(maxX - minX) << "\n";
}


/*  things to check:
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
    4) clear
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

