#include <bits/stdc++.h>

using namespace std;

long long linear(vector<int> &a, int x, int day) {
    long long r = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] + (i + 1) * day <= x) {
            r = i + 1;
        }
        else break;
    }

    return r;
}


long long binary(vector<int> &a, int x, int day) {
    int l = 0;
    int r = a.size() - 1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (a[mid] + (mid + 1) * day == x) {
            return mid + 1;
        }
        else if (a[mid] + (mid + 1) * day > x) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }


    if (l > a.size() - 1) {
        return a.size();
    }
    if (r < 0) {
        return 0;
    }
    return r + 1;
}

void s() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }

    long long res = 0;
    int j = 0;
    while(true) {
        long long sum = binary(a, x, j);
        // cout << sum << " day:" << j << '\n';
        if (sum == 0) {
            break;
        }
        res += sum;
        j++;

    }

    cout << res << "\n";
}

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] <= x) {
            cnt += 
        }
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