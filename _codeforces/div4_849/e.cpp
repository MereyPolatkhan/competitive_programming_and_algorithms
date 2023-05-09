#include <bits/stdc++.h>

using namespace std;




void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    
    int neg = 0;
    int minabs = INT_MAX;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            neg++;
        }
        sum += abs(a[i]);
        minabs = min(minabs, abs(a[i]));
    }

    if (neg % 2 == 0) {
        cout << sum << "\n";
    }
    else {
        cout << sum - minabs*2 << "\n";
    }

    // cout << sum << " " << minabs << "\n";

}


int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    while (n--){
        solve();
    }

    return 0;
}