#include <bits/stdc++.h>

using namespace std;

vector<int> kmp(string s) {
    int n = s.size();
    vector<int> p(n, 0);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        p[i] = j;
    }
    return p;
}

char lower(char c) {
    return char(c + 32);
}

char upper(char c) {
    return char(c - 32);
}

int main() {

    string s;
    cin >> s;

    int k;
    cin >> k;

    vector<pair<string, int>> res; 
    int mx;
    while (k--) {
        string t;
        cin >> t;
        t[0] = lower(t[0]);
        string q = t + "$" + s;
        vector<int> p = kmp(q);

        mx = -1;
        mx = max(p[p.size() - 1], mx);
         

        res.push_back({t, mx});
    }

    mx = -1;
    for (auto i: res){ 
        mx = max(mx, i.second);
        // cout << i.first << " " << i.second << "\n";
    }

    vector<string> finalRes;

    for (auto i: res) {
        if (i.second == mx && i.second != 0) {
            i.first[0] = upper(i.first[0]);
            finalRes.push_back(i.first);
        }
    }

    cout << finalRes.size() << "\n";
    for (auto i: finalRes) cout << i << "\n";


    return 0;
}