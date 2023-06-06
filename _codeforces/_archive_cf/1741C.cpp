#include <bits/stdc++.h>

using namespace std;

int n;
int calc_max_width(int sum, vector<int>& a) {
    int cur_sum = 0;
    int from = 1;
    int max_w = -1e9;
    for (int i = 1; i <= n; i++) {
        cur_sum += a[i];
        if (cur_sum == sum) {
            max_w = max(max_w, i - from + 1);
            from = i + 1;
            cur_sum = 0;
        }
    }
    if (from == n + 1) {
        return max_w;
    }
    return (int)1e9;
}

void solve() {
    cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int res = (int)1e9;

    int left_sum = 0;
    int right_sum = 0;

    int i = 1;
    int j = n;

    while (i <= j) {
        if (left_sum == right_sum) {
            res = min(res, calc_max_width(left_sum, a));
            left_sum += a[i]; i++;
            right_sum += a[j]; j--;
        }
        else if (left_sum < right_sum) {
            left_sum += a[i]; i++;
        }
        else {
            right_sum += a[j]; j--;
        }
    }
    if (left_sum == right_sum) {
        res = min(res, calc_max_width(left_sum, a));
    }
    if (res == (int)1e9) {
        cout << n << "\n";
    }
    else {
        cout << res << "\n";
    }

}


int main() {
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