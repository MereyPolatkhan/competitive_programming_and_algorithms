#include <bits/stdc++.h>

using namespace std;

int count(int n) {
    int sum = 0;

    while (n > 0) {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}

void solve() {

    int n, q;
    cin >> n >> q;

    int a[n];

    for (int i = 0; i < n; i++) cin >> a[i];


    vector<bool> used(n, false);


    while (q--) {
        int wh;
        cin >> wh;
        if (wh == 1) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            for (int i = l; i <= r; i++) {
                // if (used[i] == false) {
                    a[i] = count(a[i]);
                    // used[i] = true;
                // }
            }
        }
        else if (wh == 2) {
            int x;
            cin >> x;
            x--;

            cout << a[x] << "\n";
        }
    }

}




int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    while (n--){
        solve();
    }

    return 0;
}