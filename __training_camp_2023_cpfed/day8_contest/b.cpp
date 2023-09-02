#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;





void solve() {
    ll n, avg;
    cin >> n >> avg;

    ll l = 0;
    ll r = n + 1;
    while (l < r - 1) {
        ll mid = (l + r) / 2;
        if ((mid * (mid + 1) / 2) + (n - mid) <= n * avg) {
            l = mid;
        }   
        else {
            r = mid;
        }
    }

    cout << l << "\n";
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

