#include <bits/stdc++.h>

using namespace std;

void solve() {
    vector<string> a;

    string s;
    cin >> s;
    int n = s.size();

    if (s[0] == s[n - 1]) {
        cout << s.substr(0, 1) << " " << s.substr(1, n - 2) << " " << s.substr(n - 1, 1);
    } 
    else {
        if (s[1] == 'a') {
            a.push_back(s.substr(0, 1));
            a.push_back(s.substr(1, 1));
            a.push_back(s.substr(2, n-2));

        }
        else if (s[1] == 'b') {
            a.push_back(s.substr(0, 1));
            a.push_back(s.substr(1, n - 2));
            a.push_back(s.substr(n - 1, 1));
        }
    }
    for (auto i: a) cout << i << " "; cout << "\n";
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}