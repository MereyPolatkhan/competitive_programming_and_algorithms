#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<char, int> m;
    
    string s;
    int h = 0;
    while (cin >> s) {
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
            h = max(h, m[s[i]]);
        }
    }
    
    string res = "";
    
    for (auto i: m) {
        res += i.first;
    }

    while (h > 0) {
        string cur = "";
        for (int i = 0; i < res.size(); i++) {
            if (m[res[i]] >= h) {
                cur += "#";
            }
            else {
                cur += " ";
            }
        }       
        cout << cur << "\n";

        h--;
    }
    cout << res;
    return 0;
}