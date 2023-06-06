#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


pair<ll, ll> between(vector<ll> & a, ll n, ll p) {
    ll res_len = 1e9;
    ll left = 1, right = 1;

    ll s = 0;
    ll l = 1;

    // cout << "a: "; for (ll r = 1; r <= 2 * n; r++) cout << a[r] << " "; cout << "\n\n";
    for (ll r = 1; r <= 2 * n; r++) {
        s += a[r];
        while (s - a[l] >= p) {
            s -= a[l];
            l++;
        }
        if (s >= p) {
            if (res_len > (r - l + 1)) {
                res_len = r - l + 1;
                left = l;
                right = r;
            }
        }
        // cout << "s : " << s  << "  l : " << l << "  r: " << r << "\n";
    }
    return {left, right};
}

pair<ll, ll> beginn(vector<ll> & a, ll n, ll p) {
    ll l = 1;
    ll r = 1;
    ll s = 0;
    while (r <= n) {
        s += a[r];
        if (s >= p) {
            break;
        }
        r++;
    }
    return {l, r};
}

pair<ll, ll> endd(vector<ll> & a, ll n, ll p) {
    ll l = n;
    ll r = n;
    ll s = 0;
    while (1 <= l) {
        s += a[l];
        if (s >= p) {
            break;
        }
        l--;
    }
    return {l, r};
}

ll calc(pair<ll, ll> range) {
    return range.second - range.first + 1;
}

int main() {
    ll n, p;
    cin >> n >> p;

    ll sum = 0;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    ll cir = p / sum;
    p = p % sum;
    // cout << "cir: " << cir << "  p : " << p << "\n\n\n";
    for (ll i = 1; i <= n; i++) {
        a.push_back(a[i]);
    }

    pair<ll, ll> btw = between(a, n, p);
    pair<ll, ll> bgn = beginn(a, n, p);
    pair<ll, ll> end = endd(a, n, p);

    if (calc(btw) <= calc(bgn) and calc(btw) <= calc(end)) {
        cout << btw.first << " " << calc(btw) + cir * n;
    }
    else if (calc(bgn) <= calc(btw) and calc(bgn) <= calc(end)) {
        cout << 1 << " " << calc(bgn) + cir * n;
    }
    else {
        cout << end.first << " " << calc(end) + cir * n;
    }

    return 0;
}