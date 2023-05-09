#include <bits/stdc++.h>

using namespace std;

int n;

void solve(vector<pair<int, int>> & pr) {
    vector<int> B;
    vector<int> a;

    for (auto i : pr) {
        B.push_back(i.second);
        a.push_back(i.first);
    }

    for (int i = 1; i < n; i++) {
        B[i] += B[i - 1];
    }

    if (n == 1) {
        // cout << 1 << "\n";
        cout << a[0];
        return;
    }
    else if (n == 2) {
        int res = INT_MAX;
        if (B[0] >= a[1]) {
            res = a[0];
        }
        if (B[1] - B[0] >= a[0]) {
            res = min(res, a[1]);
        }

        if (res == INT_MAX) {
            // cout << 2 << "\n";
            cout << "gg";
        }
        else {
            // cout << 3 << "\n";
            cout << res;
        }
        return;
    }   
    else {
        if (a[n - 1] > B[n - 2]) {
            // cout << 4 << "\n";
            cout << "gg";
            return;
        }
        if (B[0] >= a[n - 1]) {
            // cout << 5 << "\n";
            cout << a[0];
            return;
        }
        if (B[1] >= a[n - 1] and B[1] - B[0] >= a[0]) {
            // cout << 6 << "\n";
            cout << a[1];
            return;
        }

        int res = INT_MAX;

        for (int i = 2; i < n; i++) {
            if (a[i - 1] <= B[i - 2] + (B[i] - B[i - 1])) {
                res = min(res, a[i]);
            }
        }
        // cout << 7 << "\n";
        cout << res;
        return;
    }



}


int main() {
    cin >> n;

    // vector<int> c(n);
    // vector<int> b(n);

    // for (int i = 0; i < n; i++) cin >> c[i];
    // for (int i = 0; i < n; i++) cin >> b[i];


    vector<pair<int, int>> a(n);

    // for (int i = 0; i < n; i++) {
    //     a[i] = {c[i], b[i]};
    // }

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }

    sort(a.begin(), a.end());

    solve(a);

    return 0;
}