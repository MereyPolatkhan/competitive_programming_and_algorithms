#include <bits/stdc++.h>

using namespace std;

int func(int n, int m) {
    if (n == m) {
        return 1;
    }
    if (n % 3 == 0) {
        int fst = n / 3;
        int scd = fst * 2;
        n = n / 3;
        if (fst == m || scd == m) {
            return 1;
        }
        else {
            return max(func(fst, m), func(scd, m));
        }
    }
    else {
        return -1;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    int res = func(n, m);
    if (res > -1) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}   

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--){ 
        solve();
    }



    return 0;
}