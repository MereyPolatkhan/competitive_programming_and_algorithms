#include <bits/stdc++.h>

using namespace std;

void solve() {

    int n, m;
    cin >> n >> m;

    vector<int> b(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    sort(b.begin() + 1, b.end());

    vector<int> a;
    int init = 1;
    for (int i = 1; i <= m; i++) {
        int x = b[i];

        a.push_back(x - init);
        init = x + 1;

        if (i == m) {
            a[0] += n - x;
        }
    }

    
    sort(a.rbegin(), a.rend());

    // cout << "a: "; for (int i : a) cout << i << " "; cout << "\n";

    int all = 0;
    int y = 0;

    for (int &x: a) {
        x -= y;
        y += 4;
        if (x == 1) all++;
        else if (x >= 2) all += (x - 1); 
    }
    
    // cout << "all: " << all << " ";
    cout << n - all << "\n";

}

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
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