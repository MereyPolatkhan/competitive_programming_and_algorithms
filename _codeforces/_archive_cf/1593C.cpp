#include <bits/stdc++.h>


using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());


    for (int i = 0; i < k; i++) {
        a[i] = n - a[i];
    }

    int sum = 0;
    int cnt = 0;
    for (int i = k - 1; i >= 0; i--) {
        if (sum + a[i] < n) {
            sum += a[i];
            cnt++;
        }
    }   
    cout << cnt << "\n";

}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}