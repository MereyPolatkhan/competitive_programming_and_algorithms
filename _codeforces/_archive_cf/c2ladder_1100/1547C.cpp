#include <bits/stdc++.h>


using namespace std;

void solve() {
    int k, n, m;
    cin >> k >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    vector<int> b(m + 1);
    for (int i = 1; i <= m; i++) cin >> b[i];

    int i = 1;
    int j = 1;

    vector<int> res;

    while (i <= n and j <= m) {
        // cout << i << " " << j << "\n";
        if (a[i] == 0) {
            k++;
            res.push_back(0); 
            i++;
        }
        else if (b[j] == 0) {
            k++;
            res.push_back(0); 
            j++;
        }
        else {
            if (a[i] < b[j] and a[i] <= k) {
                res.push_back(a[i]); 
                i++;
            }
            else if (a[i] >= b[j] and b[j] <= k) {
                res.push_back(b[j]); 
                j++;
            }
            else {
                cout << -1 << "\n";
                return;
            }
        }
    }

    while (i <= n) {
        if (a[i] == 0) {
            res.push_back(a[i]); 
            i++;
            k++;
        }
        else if (a[i] <= k) {
            res.push_back(a[i]); 
            i++;
        }
        else {
            cout << -1 << "\n";
            return;
        }
    }
    
    while (j <= m) {
        if (b[j] == 0) {
            res.push_back(b[j]); 
            j++;
            k++;
        }
        else if (b[j] <= k) {
            res.push_back(b[j]); 
            j++;
        }
        else {
            cout << -1 << "\n";
            return;
        }
    }


    
    for (int & i : res) cout << i << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}