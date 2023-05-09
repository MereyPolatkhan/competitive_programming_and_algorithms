#include <bits/stdc++.h>

using namespace std;

void solve() {

    int n;
    cin >> n;
    int m = n - 1;
    int a[n][m];
    
    vector<int> cnt(n + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (j == 0){
                cnt[a[i][j]] += 1;
            }
        }
    }    


    vector<int> p(n, 0);

    for (int i = 1; i <= n; i++) {
        if (cnt[i] == n - 1) {
            p[0] = i;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i][0] != p[0]) {
            for (int j = 0; j < m; j++) {
                p[j + 1] = a[i][j];
            }
        }
    }

    for (auto i:p)cout << i << " ";
    cout << "\n";

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