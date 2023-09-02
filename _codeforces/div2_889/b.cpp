#include <bits/stdc++.h>


using namespace std;

void solve() {

    long long n;
    cin >> n;

    vector<int> a;

    for (int i = 1; i <= 50; i++) {
        if (n % i == 0) {
            a.push_back(i);
        }
    }

    int cnt = 1;
    int res = 1;

    int i = 0;
    while (i < a.size() - 1) {
        if (a[i] + 1 == a[i + 1]) {
            cnt++;
        } 
        else {
            res = max(res, cnt);
            cnt = 1;
        }
        i++;
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