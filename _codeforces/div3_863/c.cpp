#include <bits/stdc++.h>

using namespace std;

void solve() {
    
    int n;
    cin >> n;

    int m = n - 1;
    vector<int> b(m);

    for (int i = 0; i < m; i++) cin >> b[i];

    b.push_back(0);

    vector<int> a;
    int i = 0; 
    while (i < m) {
        if (b[i] < b[i + 1]) {
            a.push_back(b[i]);
            a.push_back(0);   
            i++;
        }
        else if (b[i] == b[i + 1]) {
            a.push_back(b[i]);
        }
        else if (b[i] > b[i + 1]) {
            a.push_back(b[i]);
        }
        i++;
    }
    
    for (int i = 0; i < m + 1; i++) cout << b[i] << " ";
    cout << " -> ";

    for (int i : a) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    freopen("output.txt", "w", stdout);
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