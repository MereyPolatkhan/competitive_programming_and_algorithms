#include <bits/stdc++.h>

using namespace std;

void solve() {

    int n;
    cin >> n;

    string s;
    cin >> s;


    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i - 1] == s[i + 1]) n--;
    }

    cout << n - 1 << "\n";
}

int main() {    

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