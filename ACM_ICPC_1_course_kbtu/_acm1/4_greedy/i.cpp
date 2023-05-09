#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
    if (a.first - a.second == b.first - b.second) {
        return a.first < b.first;
    }

    return a.first - a.second < b.first - b.second;
}

void solve() {
    long long n, budget;
    cin >> n >> budget;

    vector<long long> b(n);
    vector<long long> c(n);

    for (long long i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (long long i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector< pair<long long, long long> > a;
    for (long long i = 0; i < n; i++) {
        a.push_back({b[i], c[i]});
    }

    sort(a.begin(), a.end(), cmp);

    long long cnt = 0;
    long long i = 0;
    
    while (i < n and budget > 0) {
        
        if (budget >= a[i].first) {
            if (budget / a[i].first >= 2) {
                int raz = floor(budget / a[i].first);
                cnt += raz;
                budget -= raz * a[i].first;
                budget += raz * a[i].second;
            }
            else {
                cnt++;
                budget -= a[i].first;
                budget += a[i].second;
            }
         }
        else {
            i++;
        }
        
    }

    cout << cnt << "\n";

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    long long t;
    cin >> t;

    while (t--) {
        solve();
    }


    return 0;
}