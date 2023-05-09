#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define ull unsigned long long 
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)


void solve(ll n) {

    ll all = n;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            all = all - (all / i);
            while (n % i == 0) {
                n = n / i;
            }
        }
    }

    // cout << "n = " << n <<  " all: " << all << "\n";

    if (n > 1) {
        all = all - (all / n);
    }

    cout << all << "\n";
}

int main() {
    fast;
    // read;
    // write;

    while (true) {
        ll n; cin >> n;
        if (n == 0) return 0;
        solve(n);
    }
 
    
 
    return 0;
}