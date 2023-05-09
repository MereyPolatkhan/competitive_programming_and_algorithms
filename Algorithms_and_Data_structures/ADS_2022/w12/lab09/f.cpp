#include <bits/stdc++.h>

using namespace std;




int main() {
    string s;
    cin >> s;
    string t;
    cin >> t;

    s = t + "$" + s;

    vector<int> p(s.size(), 0);
    for (int i = 1; i < s.size(); i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) j = p[j - 1];
        if (s[i] == s[j]) j++;
        p[i] = j;
    }

    vector<int> res;
    for (int i = t.size(); i < p.size(); i++) {
        if (p[i] == t.size()) {
            res.push_back(i - 2 * t.size() + 1);
        }
    }

    cout << res.size() << "\n";
    for (auto i: res) cout << i << " ";

    return 0;
}