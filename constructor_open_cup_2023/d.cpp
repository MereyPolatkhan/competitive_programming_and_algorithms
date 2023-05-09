#include <bits/stdc++.h>

using namespace std;

void solve() {

    long long n;
    cin >> n;

    vector<int> res;

    while (n > 1) {
        long long x = (n + 1) / 2;
        if (x % 2 == 1) {
            res.push_back(1);
            n = x;
            continue;
        }

        long long y = (n - 1) / 2;
        if (y % 2 == 1) {
            res.push_back(2);
            n = y;
            continue;
        }

        else {
            res.push_back(0);
        }
    }

    reverse(res.begin(), res.end());
    for (int i : res) cout << i;
    cout << "\n";

}

int main() {
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }




    return 0;
}