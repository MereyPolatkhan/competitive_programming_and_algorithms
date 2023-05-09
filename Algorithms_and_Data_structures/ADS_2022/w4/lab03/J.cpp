#include <iostream>
#include <math.h>

#define ll long long

using namespace std;


int main() {

    ll n, h;
    cin >> n >> h;

    ll a[n];
    ll mx = -1e9 - 1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    ll res;
    ll l = 1;
    ll r = mx;
    while (l <= r) {
        ll mid = (l + r) / 2;
        ll hours = 0;
        for (int i = 0; i < n; i++) {
            hours += (int)ceil((1.0 * a[i]) / mid);
        }

        if (hours <= h) {
            res = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << res;
    return 0;
}