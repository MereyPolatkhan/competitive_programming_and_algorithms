#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define BASE 107



ull my_hash(string s) {
    ll h = 0;
    for (int i = 0; i < s.size(); i++){
        h = h * BASE + s[i];
    }
    return h;
}

ll rk(string s, string t) {
    vector<ll> ans;
    ll n = s.size();
    ll m = t.size();

    ull hs = my_hash(s.substr(0, m));
    ull ht = my_hash(t);

    ull pm = 1;
    for (int i = 0; i < m - 1; i++) {
        pm *= BASE;
    }

    for (int i = 0; i <= n - m; i++) {
        if (hs == ht) {
            ans.push_back(i);
        }
        if (i < n - m) {
            hs = (hs - pm * s[i]) * BASE + s[i + m];
        }
    }

    return ans.size();
}



void solve(ll n) {
    vector<string> word;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        word.push_back(x);
    }
    string s;
    cin >> s;
    vector< pair<string, ll> > a;

    for (int i = 0; i < n; i++) {
        a.push_back({word[i], rk(s, word[i])});
    }

    ll mx = -1;

    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i].second);
    }

    vector<string> res;


    for (int i = 0; i < n; i++) {
        if (a[i].second == mx){
            res.push_back(a[i].first);
        }
    }


    cout << mx << "\n";
    for (auto i: res) cout << i << "\n";
    
    return;

}

int main() {
    // freopen("input.txt", "r", stdin);
    while(true) {
        ll n;
        cin >> n;
        if (n == 0) {
            return 0;
        }
        else {
            solve(n);
        }
    }

    return 0;
}