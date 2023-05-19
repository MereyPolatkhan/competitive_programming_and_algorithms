#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    int n = s.size();


    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        a[i] = (int)s[i] - 48;
    }



    vector<int> res;
    int cur = a[n - 1];
    res.push_back(cur);
    for (int i = n - 2; i >= 0; i--) {
        if (cur < a[i]) {
            res.push_back(::min(a[i] + 1, 9));
        }
        else {
            cur = a[i];
            res.push_back(cur);
        }
    }
    sort(res.begin(), res.end());

    for (int i : res) cout << i;
    cout << "\n";
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