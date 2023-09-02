#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

bool cmp(pair<pii, int> a, pair<pii, int> b) {
    if (a.first.first == b.first.first) {
        if (a.first.second == b.first.second) {
            return a.second < b.second; 
        }
        return a.first.second > b.first.second;
    }

    return a.first.first < b.first.first;
}


void solve() {
    
    int n, x, y;
    cin >> n >> x >> y;

    vector<pair<pii, int>> a(n);

    for (int i = 0; i < n; i++) {
        int d, m;
        cin >> d >> m;
        a[i] = {{d, m}, i + 1};
    }


    sort(all(a), cmp);

    for (int i = 0; i < n; i++) {
        if (a[i].first.first <= x and a[i].first.second >= y) {
            cout << a[i].second << "\n";
            return;
        }
    }
    cout << -1 << "\n";
    return;

}


/*  things to check:
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
    4) clear
*/





int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

