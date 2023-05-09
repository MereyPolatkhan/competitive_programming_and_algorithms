#include <bits/stdc++.h>

using namespace std;

void solve(){

    int a, b, c, d;
    cin >> a >> b >> d >> c;

    for (int i = 0; i < 4; i++) {
        if (a < b && d < c && a < d && b < c) {
            cout << "YES\n";
            return;
        }
        else {
            int cur_a = a;
            a = b;
            b = c;
            c = d;
            d = cur_a;
        }
    }
    cout << "NO\n";
}

int main() {
    // freope   n("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}