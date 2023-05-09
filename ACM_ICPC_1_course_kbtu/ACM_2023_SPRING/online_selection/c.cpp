#include <bits/stdc++.h>

using namespace std;

void solve() {
    
    int h, m;
    cin >> h >> m;

    int res = 60 - m;

    h++;
    res += (24 - h) * 60;

    cout << res << "\n";

}


int main() {
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }


    return 0;
}