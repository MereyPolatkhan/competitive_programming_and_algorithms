#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    unordered_map<char, char> mp;


    for (int i = 0; i < n; i++) {
        if (i == 0){ 
            mp[s[i]] = '1';
        }    
        else {
            if (s[i - 1] == s[i]) {
                cout << "NO\n";
                return;
            }

            else if (mp.count(s[i]) == 0) {
                if (mp[s[i - 1]] == '1') {
                    mp[s[i]] = '0';
                }
                else {
                    mp[s[i]] = '1';
                }
            }
            else if (mp.count(s[i])) {
                if (mp[s[i]] == mp[s[i - 1]]) {
                    cout << "NO\n";
                    return;
                }
            }
            else {
                cout << "NO\n";
                return;
            }
        }
    }

    cout <<"YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }





    return 0;
}