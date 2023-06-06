#include <bits/stdc++.h>


using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    reverse(a.begin(), a.end());

    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        b[i] = a[i - 1];
    }

    int i = 1;
    int cnt = 0;
        
    while (i <= n) { 
        if (b[i] == b[1]) {
            i++;
        }
        else {
            i *= 2;
            i--;
            cnt++;
        }
    }
    cout << cnt << "\n";
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << "===========Answers===========\n";
    int t;
    cin >> t;
    while (t--) {
        solve();
    }


    return 0;
}