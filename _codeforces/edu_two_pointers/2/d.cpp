#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
int main() {
    
    ll n, s;
    cin >> n >> s;
 
    vector<ll> a(n);
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    ll l = 0;
    ll sum = 0;
    ll cnt = 0;
 
    for (int r = 0; r < n; r++) {
        sum += a[r];
        if (sum >= s) {
            cnt++;
        }
        while (sum - a[l] >= s) {
            cnt += (n - r);
            sum -= a[l];
            l++;
        }
    }
 
    cout << cnt;
 
    return 0;
}
