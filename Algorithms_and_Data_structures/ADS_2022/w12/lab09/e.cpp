#include <bits/stdc++.h>

using namespace std;

vector<int> kmp(string s) {
    int n = s.size();
    vector<int> p(n);

    p[0] = 0;

    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[j] != s[i]) {
            j = p[j - 1];
        }
        if (s[i] == s[j] ){
            j++;
        }
        p[i] = j;
    }
    return p;
}


void solve() {
    string s;
    cin >> s;
    int k;
    cin >> k;

    vector<int> p = kmp(s);

    int cur_cnt = p[p.size() - 1];
    
    int mini_sz = s.size() - cur_cnt;

    int res = s.size() + mini_sz * (k - 1);
    cout << res << "\n";
}


int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }


    return 0;
}