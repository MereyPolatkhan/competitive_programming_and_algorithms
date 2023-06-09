#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

ull width, height, n;
ull l, r;

bool good(ull x) {
    return (double)(x / width) * (x / height) >= n;
}

void solve() {
    cin >> width >> height >> n;

    l = 0, r = (ull)1e18;
    while (l <= r) {
        ull m = (l + r) / 2;
        if (good(m)) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
        // cout << l << " " << r << "\n";
    }   
    cout << l;

}

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
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
