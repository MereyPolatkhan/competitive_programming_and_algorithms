#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <math.h>

#define ull unsigned long long
#define P 31
using namespace std;

ull my_hash(string s) {
    ull h = 0;
    for (int i = 0; i < s.size(); i++) {
        h = h * P + s[i];
    }
    return h;
}

void naive_solve() { // O(n^3) * O(logn)
    map<ull, int> m;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 1; j < s.size() - i + 1; j++) {
            string cur = s.substr(i, j);
            ull h = my_hash(cur);
            m[h]++;
        }
    }
    cout << m.size();
}


void rk(string s, int m, unordered_map<ull, int>& mp) { // O(n)
    int n = s.size();

    string sub = s.substr(0, m);
    ull hw = my_hash(sub);

    ull pm = 1;
    for (int i = 0; i < m - 1; i++) {
        pm = pm * P;
    }

    for (int i = 0; i + m <= n; i++) {
        mp[hw]++;
        if (i + m < n) {
            hw = (hw - pm * s[i]) * P + s[i + m];
        }
    }
}

void solve() { // O(n^2)
    unordered_map<ull, int> mp;
    string s;
    cin >> s;
    for (int sz = 1; sz <= s.size(); sz++) {
        rk(s, sz, mp);
    }
    cout << mp.size();
}


int main() {
    solve();

    return 0;
}