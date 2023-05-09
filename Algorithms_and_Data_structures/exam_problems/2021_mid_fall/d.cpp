#include <bits/stdc++.h>

using namespace std;

int bs(vector<int>& a, int x) { // binary search for reversed array (descending)
    int l = 0;
    int r = a.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == x) {
            return mid;
        }
        else if (a[mid] < x) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return -1;
}

int main() {

    freopen("input.txt", "r", stdin);

    int t;
    cin >> t;
    int req[t];

    for (int i = 0; i < t; i++) {
        cin >> req[i];
    }

    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> a;
    vector<pair<int, int> > coord;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                a.push_back(arr[i][j]);
                coord.push_back({i, j});
            }
        }
        else {
            for (int j = m - 1; j >= 0; j--) {
                a.push_back(arr[i][j]);
                coord.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < t; i++) {
        int ind = bs(a, req[i]);
        if (ind == -1) {
            cout << -1 << "\n";
        }
        else {
            cout << coord[ind].first << " " << coord[ind].second << "\n";
        }
    }
    return 0;

}