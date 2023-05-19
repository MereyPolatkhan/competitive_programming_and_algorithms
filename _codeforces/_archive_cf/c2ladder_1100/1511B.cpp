#include <bits/stdc++.h>



using namespace std;

typedef long long ll;

void solve() { 
    int a, b, c;
    cin >> a >> b >> c;

    string x = "1";
    for (int i = 0; i < a - 1; i++) {
        x += '0';
    }

    string y = "";
    for (int i = 0; i < b - c + 1; i++) {
        y += '1';
    }
    for (int i = 0; i < c - 1; i++) {
        y += '0';
    }

    cout << x << " " << y << "\n";
}



int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}