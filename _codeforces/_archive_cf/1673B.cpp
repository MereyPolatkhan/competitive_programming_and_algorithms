#include <bits/stdc++.h>

using namespace std;

void solve() {



    string s;
    cin >> s;

    unordered_map<char, int> mp;

    int k = -1;

    for (int i = 0; i < s.size(); i++) {
        if (mp.count(s[i])){
            k = i;
            break;
        }
        else {
            mp[s[i]]++;
        }
    }

    for (int i = k; i < s.size(); i++) {
        if (s[i] == s[i - k]) {
            continue;
        }
        else {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}