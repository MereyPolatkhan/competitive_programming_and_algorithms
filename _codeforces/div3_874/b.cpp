#include <bits/stdc++.h>

using namespace std;

const int minf = -1e9 - 9;

int n, k;

int search(int ai, vector<int> & b, vector<bool> & used) {
    int l = 0;
    int r = n - 1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (b[mid] == ai) {
            used[mid] = true;
            return b[mid];
        }
        else if (b[mid] < ai) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }



    if (r < 0) {
        for (int i = 0; i < n; i++) {
            if (used[i] == false and abs(b[i] - ai) <= k) {
                used[i] = true;
                return b[i];
            }
        }
    }

    if (l >= n) {
        for (int i = n - 1; i >= 0; i--) {
            if (used[i] == false and abs(b[i] - ai) <= k) {
                used[i] = true;
                return b[i];
            }
        }
    }

    while (0 <= l and r < n) {
        if (used[l] == false and abs(b[l] - ai) <= k) {
            used[l] = true;
            return b[l];
        }
        l--;
        if (used[r] == false and abs(b[r] - ai) <= k) {
            used[r] = true;
            return b[r];
        }
        r++;
    }

    return minf;

}

void solve() {
    cin >> n >> k;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }


    sort(b.begin(), b.end());
    sort(a.begin(), a.end());

    vector<int> res(n);

    for (int i = 0; i < n; i++) {
        res[a[i].second] = b[i];
    }
    for (int i : res) cout << i << " ";
    cout << "\n";
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

/*  things to check:
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
    4) clear
*/
