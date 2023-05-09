#include <bits/stdc++.h>


using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    if (n <= m) {
        cout << 1;
        return;
    }
    if (m == 1) {
        if (n % 2 == 0) cout << 2;
        else cout << 1;
        return;
    }

    if (n % (m + 1) == 0) {
        cout << 2;
    }     
    else cout << 1;
    
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }



    return 0;
}