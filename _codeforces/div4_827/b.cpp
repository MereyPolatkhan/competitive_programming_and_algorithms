#include <iostream>
#include <map>
#define ll long long
using namespace std;

void solve() {
    ll n;
    cin >> n;
    map<ll, ll> m;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        m[x]++;
        if (m[x] >= 2){ 
            cout << "NO\n";
            return;
        }
    }   
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("input.txt", "r", stdin);
    ll t;
    cin >> t;
    
    while (t--){
        solve();       
    }
    return 0;
}