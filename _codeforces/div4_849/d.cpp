#include <bits/stdc++.h>

using namespace std;




void solve() {

    int n;
    cin >> n;
    string s;
    cin >> s;

    unordered_map<char, int> mp1;
    unordered_map<char, int> mp2;

    for (int i = 0; i < n; i++) {
        mp1[s[i]]++;
    }
    
    // cout << "\n\n";
    int res = -1e9;
    for (int i = n - 1; i >= 0; i--) {
        mp1[s[i]]--;
        mp2[s[i]]++;
        if (mp1[s[i]] == 0) mp1.erase(s[i]);
        if (mp2[s[i]] == 0) mp2.erase(s[i]);

        if (mp1.size() and mp2.size()) 
            res = max(res, int(mp1.size() + mp2.size()));

        // cout << s[i] << " " << res << "\n"; 
    }

    cout << res << "\n";
    // cout << "\n\n";



}




int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    while (n--){
        solve();
    }

    return 0;
}