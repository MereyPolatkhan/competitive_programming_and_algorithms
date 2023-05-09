#include <bits/stdc++.h>

using namespace std;

int n, m;

bool check(int index, int x, vector<int> a, vector<int> b) {
    a[index] = x;
    
    double res = 1.0;

    for (int i = 0; i < n; i++) {
        res *= ((a[i] * (1.0)) / (b[i] * (1.0)));
    }

    return res >= 1.0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];


    // sort(a.begin(), a.end());
    // sort(b.begin(), b.end());

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        int l = 0;
        int r = m + 1;
        int res = INT_MIN; 
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(i, mid, a, b)) {
                res = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        
        if (res == INT_MIN) {
            continue;
        }

        if (res <= a[i]) { // a[0] = 10 and res = 8 
            cnt += m - res;
        }
        else {
            cnt += m - res + 1;
        }
    }

    cout << cnt;

    return 0;
}