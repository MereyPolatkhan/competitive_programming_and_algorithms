#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;


bool check(ll x) {
    string s = to_string(x);
    int n = s.size();
    
    if (n == 1) 
        return false;

    string a = s.substr(0, (n + 1) / 2);
    string b = s.substr((n + 1) / 2);

    return __gcd(stoll(a), stoll(b)) == 1;
}



void solve() {
    ll l, r;
    cin >> l >> r;

    for (ll i = r; i >= l; i--) {
        if (check(i))  {
            cout << i << "\n";
            return;
        }
    }
    cout << -1 << "\n";

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

