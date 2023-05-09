#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int sum = a + b + c;

    if ((sum) % 3 != 0) {
        cout << -1 << "\n";
        return;
    }


    int per = sum / 3;

    int cnt = 0;

    if (a > per) {
        cnt += (a - per);
    }
    if (b > per) {
        cnt += (b - per);
    }
    if (c > per) {
        cnt += (c - per);
    }
    cout << cnt << "\n";
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }




    return 0;
}