#include <bits/stdc++.h>
 
using namespace std;

#define ll long long



int main() {
    
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<ll, ll> mp;
    ll l = 0;
    ll cnt = 0;

    for (ll r = 0; r < n; r++) {
        mp[a[r]]++;
        while (mp.size() > k) {
            mp[a[l]]--;
            if (mp[a[l]] == 0) mp.erase(a[l]);
            l++;
        }
        cnt += (r - l + 1);
    }

    cout << cnt;


    return 0;
}
