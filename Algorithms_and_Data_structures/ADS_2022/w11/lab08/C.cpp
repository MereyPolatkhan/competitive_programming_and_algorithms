#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define BASE 31

ull my_hash(string s) {
    ll h = 0;
    for (int i = 0; i < s.size(); i++){
        h = h * BASE + s[i];
    }
    return h;
}


vector<pair<int, int>> a;

string s;
int n;

void rk(string t) {
    int m = t.size();

    ull ht = my_hash(t);
    ull hs = my_hash(s.substr(0, m));

    ull pm = 1;
    for (int i = 0; i < m - 1; i++) pm = pm * BASE;

    for (int i = 0; i <= n - m; i++) {
        if (ht == hs) {
            a.push_back({i, i + m - 1});
        }
        if (i < n - m) hs = (hs - s[i] * pm) * BASE + s[i + m];
    }
}


int main(){

    cin >> s;
    n = s.size();
    
    int k;
    cin >> k;    
    for (int i = 0; i < k; i++) {
        string t;
        cin >> t;
        rk(t);
    }
    sort(a.begin(), a.end());

    // for (auto i: a) cout << i.first << " " << i.second << "\n";

    if (a[0].first > 0) {
        cout << "NO\n";
        return 0;
    }

    for (int i = 1; i < a.size(); i++) {
        if (a[i].first - a[i - 1].second >= 2) {
            cout << "NO\n";
            return 0;
        }
    }

    if (a[a.size() - 1].second < s.size() - 1) {
        cout << "NO\n";
        return 0;
    }
    
    cout << "YES\n";
    
    return 0;
}