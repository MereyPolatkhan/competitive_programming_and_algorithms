#include <bits/stdc++.h>


using namespace std;
 
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}


void solve() {
    int n;
    cin >> n;

    vector< pair<int, int> > a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin() + 1, a.end(), cmp);
    long long res = 0;
    map<int, int> mp;
    int x = 0;

    for (int i = 1; i <= n; i++) {
        int ai = a[i].first;
        int bi = a[i].second;

        if (mp[ai] == -1) {
            continue;
        }
        mp[ai]++;
        res += bi;
        x++;

        if (mp[x] >= 1) {
            int val = mp[x];
            mp[x] = -1;
            x -= val;
        }
    }
    cout << res << "\n";
}



int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}