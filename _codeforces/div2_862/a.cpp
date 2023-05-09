#include <bits/stdc++.h>

using namespace std;

const int M = 255;


int func(int x, vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        a[i] = a[i] ^ x;
    }

    // for (int i : a) cout << i << " "; cout << "\n";

    int res = a[0];

    for (int i = 1; i < a.size(); i++) {
        res = res ^ a[i];
    }

    return res;

}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }



    for (int x = 0; x <= M; x++) {
        if (func(x, a) == 0) {
            cout << x << "\n";
            return;
        }
    }
    cout << -1;
    return;

}


int main() {
    freopen("input.txt", "r", stdin);
   
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
 
    return 0;
}