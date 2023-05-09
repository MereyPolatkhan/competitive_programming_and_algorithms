#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define MOD 1000000007
#define BASE 11

ull my_pow(ull base, ull d) {
    ull res = 1;
    for (int i = 0; i < d; i++) {
        res = res * base;
        res = res % MOD;
    }
    return res;
}


ull my_hash(string s) {
    ull h = 0;
    for (int i = 0; i < s.size(); i++) {
        h = h + ((s[i] - 47) * my_pow(BASE, i)) % MOD;
        h = h % MOD;
    }
    return h;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;

    unordered_map<string, ll> m;
    vector<pair<string, ll>> a;
    
    for (int i = 0; i < 2 * n; i++) {
        string s;
        cin >> s;

        m[s] = my_hash(s);
        a.push_back({s, my_hash(s)});
    }

    int cnt = 0;
    for (auto v: a) {
        if (m.count(to_string(v.second)) == 1 && cnt < n) {
            cout << "Hash of string \"" << v.first << "\" is " << v.second << "\n";
            cnt++;
        }
    }
}