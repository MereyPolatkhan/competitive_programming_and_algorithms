#include <iostream>
#include <vector>

using namespace std;

#define ll long long

void solve() {
    int n = 8;
    int m = 8;
    char a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int r;
    int b;
    for (int i = 0; i < n; i++) {
        r = 0;
        b = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'R') {
                r++;
            }
            if (a[i][j] == 'B') {
                b++;
            }
        }
        if (r == 8) {
            cout << "R\n";
            return;
        }
        if (b == 8) {
            cout << "B\n";
            return;
        }
    }

    
    for (int j = 0; j < m; j++) {
        r = 0;
        b = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][j] == 'R') {
                r++;
            }
            if (a[i][j] == 'B') {
                b++;
            }
        }
        // cout << "r = " << r << "b == " << b << endl;
        if (r == 8) {
            cout << "R\n";
            return;
        }
        if (b == 8) {
            cout << "B\n";
            return;
        }
    }
    
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    ll n;
    while (t--){
        solve();
    }
    return 0;
}