#include <bits/stdc++.h>

using namespace std;

void solve() {

    int n;
    cin >> n;

    vector<int> a(n + 1);
    a[0] = -1e9;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (n % 2 == 1) {
        cout << "NO\n";
        return;
    }

    sort(a.begin(), a.end());

    vector<int> b; 
    b.push_back(-1e9);

    int m = n / 2;
    int i = 1;
    int j = m + 1;

    while (i < m + 1 and j < n + 1) {
        b.push_back(a[i]);
        b.push_back(a[j]);
        i++;
        j++;
    }

    for (int i = 2; i <= n; i += 2) {
        if (i == n) {
            if (b[i - 1] < b[i] and b[i] > b[1]) {
                continue;
            }
            else {
                cout << "NO\n";
                return;
            }  
        }
        else {
            if (b[i - 1] < b[i] and b[i] > b[i + 1]) {
                continue;
            }
            else {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i++) cout << b[i] << " ";
    cout << "\n";



    
}

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}