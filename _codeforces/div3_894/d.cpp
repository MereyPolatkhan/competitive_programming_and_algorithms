#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef pair<int, int> pii;

bool ch(ll n) {
    return (ll)(sqrt(1 + 8 * n)) * (ll)(sqrt(1 + 8 * n)) == (ll)((1 + 8 * n));
}


ll func(ll n) {
    while (ch(n) == false) {
        n++;
    }
    cout << n << "\n";
    return 1 + 8 * n;
}

void solve() {
    ll n;
    cin >> n;

    cout << (1 + (ll)sqrt(func(n))) / 2 << "\n";
}

int main() {   

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << "----ans---\n";

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
