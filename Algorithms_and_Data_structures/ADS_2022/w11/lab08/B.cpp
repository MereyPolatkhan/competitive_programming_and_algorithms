#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define BASE 31


ll my_hash(string s) {
    ll h = 0;
    for (int i = 0; i < s.size(); i++) {
        h = h * BASE + (int)s[i];
    }
    return h;
}

vector<ll> rk(string s, string t) {
    vector<ll> ans;
    ll n = s.size();
    ll m = t.size();

    ll ht = my_hash(t);
    ll hs = my_hash(s.substr(0, m));

    ll pm = 1;
    for (int i = 0; i < m - 1; i++) {
        pm *= BASE;
    }

    for (int i = 0; i <= n - m; i++) {
        if (hs == ht) {
            ans.push_back(i);
        }
        if (i < n - m) {
            hs = ((hs - pm * s[i]) * BASE) + s[i + m];
        }
    }
    return ans;
}

int main() {
    string s1, s2, t;
    cin >> s1 >> s2 >> t;

    vector<ll> a = rk(s1, t);
    vector<ll> b = rk(s2, t);

    unordered_map<ll, ll> m;

    for (auto i: a) {
        m[i]++;
    }
    ll cnt = 0;
    for (auto i: b) {
        if (m[i]) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}