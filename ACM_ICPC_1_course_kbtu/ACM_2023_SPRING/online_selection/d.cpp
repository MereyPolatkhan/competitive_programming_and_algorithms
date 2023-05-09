#include <bits/stdc++.h>

using namespace std;

void solve() {

    long long a, b, k;
    cin >> a >> b >> k;
    
    long long left = k / 2;
    long long right = k - left;

    cout << a * right - b * left << "\n";


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