#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll my_pow(ll base, ll n) {
    ll k = 1;
    for (ll i = 0; i < n; i++) {
        k = k * base;
    }
    return k;
}

ll my_hash(string s) {
    ll h = 0;
    for (int i = 0; i < s.size(); i++) {
        h = h + (s[i] - 97) * my_pow(2, i);  
    }
    return h;
}

char re_hash(ll h, int i) {
    return char((h / my_pow(2, i)) + 97);
}

int main() {
    int n;
    cin >> n;

    ll a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    string res = "";

    for (int i = 0; i < n; i++) {
        char c;
        if (i == 0) {
            c = re_hash(a[i], i);
        }
        else {
            c = re_hash(a[i] - a[i - 1], i);
        }
        res += c;
    }

    cout << res;
    return 0;
}