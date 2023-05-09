#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v;
    
    int l = 1;
    int r = -1;

    int a, b, c, d;
    
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        a = max(max(a, b), max(c, d));
        r = max(r, a);
        v.push_back(a);
    }

    int res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        int cnt = 0;
        for (auto i: v) {
            if (mid >= i)  {
                cnt++;
            }
        }

        if (cnt >= k) {
            res = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << res;

    return 0;
}