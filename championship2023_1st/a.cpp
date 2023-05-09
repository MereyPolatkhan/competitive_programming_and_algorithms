#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int utc = 11 + (n - 6);
    if (utc < 0) {
        utc = 24 + utc;   
    }

    if (utc == 24) {
        cout << "00:00" << "\n";
    }
    else if (utc >= 10) {
        cout << utc << ":00" << "\n";
    }
    else {
        cout << "0" << utc << ":00" << "\n";
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }



    return 0;
}