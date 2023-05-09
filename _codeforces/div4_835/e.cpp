#include <bits/stdc++.h>

using namespace std;

long long count(vector<int> a) {
    int n = a.size();
    long long cnt1 = 0;
    long long inv = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            cnt1++;
        }
        else {
            inv += cnt1;
        }
    }
    return inv;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long initial = count(a);

    long long begin = 0, end = 0;
    
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            a[i] = 1;
            begin = count(a);
            a[i] = 0;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 1) {
            a[i] = 0;
            end = count(a);
            a[i] = 1;
            break;
        }
    }

    cout << max(max(begin, end), initial) << "\n";
}


int main() {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}