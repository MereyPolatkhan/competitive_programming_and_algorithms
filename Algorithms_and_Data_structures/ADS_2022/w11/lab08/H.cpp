#include <bits/stdc++.h>

using namespace std;


#define ull unsigned long long
#define P 31

unordered_map<ull, pair<int, int>> mp;

ull my_hash(string s) {
    ull h = 0;
    for (int i = 0; i < s.size(); i++) {
        h = h * P + s[i];
    }
    return h;
}

void rk1(string s, int m) {
    int n = s.size();

    string sub = s.substr(0, m);
    ull hw = my_hash(sub);

    ull pm = 1;
    for (int i = 0; i < m - 1; i++) {
        pm = pm * P;
    }

    for (int i = 0; i + m <= n; i++) {
        mp[hw].first = 1;
        mp[hw].second = m;
        hw = (hw - pm * s[i]) * P + s[i + m];
    }
}

void rk2(string s, int m) {
    int n = s.size();

    string sub = s.substr(0, m);
    ull hw = my_hash(sub);

    ull pm = 1;
    for (int i = 0; i < m - 1; i++) {
        pm = pm * P;
    }

    for (int i = 0; i + m <= n; i++) {
        if (mp.count(hw)) {
            mp[hw].first++;
            mp[hw].second = m;
        }
        hw = (hw - pm * s[i]) * P + s[i + m];
    }
}

string result(string s, ull h2, int m) {
    int n = s.size();

    for (int i = 0; i <= n - m; i++) {
        string sub = s.substr(i, m);
        if (h2 == my_hash(sub)) {
            return sub;
        }
    }   
    
    return "NOTHING";
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

   
    int n;
    cin >> n;

    string t;
    cin >> t;

    for (int i = 1; i <= t.size(); i++) {
        rk1(t, i);
    }

    for (int k = 1; k < n; k++) {
        string s;
        cin >> s;
        for (int i = 1; i <= s.size(); i++) {
            rk2(s, i);
        }
    }

    ull res_hash;
    int len = 0;
    for (auto i: mp) {
        if (i.second.first >= n) {
            len = max(len, i.second.second);
            if (i.second.second == len) {
                res_hash = i.first;
            }
        }
        // cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
    }

    cout << result(t, res_hash, len);

    return 0;
}