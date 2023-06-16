#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


void solve() { 
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << (n - 1) / 2 << " " << (n - 1) / 2 + 1 << " " << 1 << "\n";
    }
    else {
        int b = (n - 1) / 2;
        if (b % 2 == 0) {
            cout << b - 1 << " " << b + 1 << " " << 1 << "\n";
        }
        else {
            cout << b - 2 << " " << b + 2 << " " << 1 << "\n";
        }
    }
}



int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }


    return 0;
}