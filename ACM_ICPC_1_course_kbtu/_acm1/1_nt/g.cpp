#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define ull unsigned long long 
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)


ll sz = 1e6 + 7;
vector<bool> used(sz, false);
ll n = (ll)1e6 + 7;
vector<ull> m;

ll bs(ull x) {
    ll l = 0, r = m.size()-1;
    while (l <= r) {
        // cout << l << " -- " << r << "\n\n";
        ll mid = (l + r) / 2;
        if (m[mid] == x) {
            return mid + 1;
        }
        else if (m[mid] < x) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    ull BIG = 1000000000000 + 7;
    fast;
    // read;
    // write;


    for (ll i = 2; i <= sqrt(n); i++) {
        if (used[i] == false) {
            for (ll j = i * i; j <= n; j += i) {
                used[j] = true;
            }
        }
    }

    for (ll i = 2; i <= n; i++) {
        if (used[i] == false) {
            ull aprime = i * i;
            while (aprime <= BIG) {
                m.push_back(aprime);
                aprime = aprime * i;
            }
        }
    }

    sort(m.begin(), m.end());

    // cout << m.size();
    
    ll t;
    cin >> t;
    while (t--) {
        ull low, high;
        cin >> low >> high;

        cout << bs(high) - bs(low - 1) << "\n";
    }


    return 0;
}