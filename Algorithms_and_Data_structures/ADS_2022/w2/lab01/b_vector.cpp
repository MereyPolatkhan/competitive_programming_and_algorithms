#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a;
    vector<int> res;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back(x);
        if (i == 0) {
            res.push_back(-1);
        }
        else {
            int r = 1234567;
            for (int j = i-1; j >= 0; j--) {
                if (a[j] <= x) {
                    r = a[j];
                    break;
                }
            }
            if (r == 1234567) {
                res.push_back(-1);
            }
            else {
                res.push_back(r);
            }
        }
    }

    for (auto i: res) cout << i << " ";

    return 0;
}