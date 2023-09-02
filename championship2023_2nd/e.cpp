#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

void print(vector<ll>& a) {
    cout << " ==> ";
    for (ll &i: a) cout << i << " ";
    cout << "\n\n";
}

vector<int> factorization(int n) {
    vector<int> res;
    for (int i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            // cout << i << " ";
            res.pb(i);
            n = n / i;
        }
    }
    // if (n > 1) cout << n << " ";
    if (n > 1) res.pb(n);

    return res;
} 


vector<ll> divisors(ll n) {
    vector<ll> res;
    for (ll i = 1; i <= sqrt(n); i++){
        if (n % i == 0) {
            if (n / i == i){
                // cout <<" "<< i;
                res.pb(i);
            }
            else {
                // cout << " "<< i << " " << n/i;
                res.pb(i);
                res.pb(n / i);
            } 
        }
    }
    sort(all(res));
    return res;
}

void solve() {

    ll s;
    cin >> s;

    vector<ll> a = divisors(s);

    ll res = (ll)1e18 * 4;

    for (ll x: a) {
        if (x * x >= s) {
            res = min(res, x * x);
        }
    }
    
    cout << res - s << "\n";
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
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

