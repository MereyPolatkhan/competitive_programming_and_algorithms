#include <bits/stdc++.h>

using namespace std;

int make(int n){ 
    return floor(n * 1.0 / 2.0);
}

void solve() {
    
    vector <int> odd;
    vector <int> even;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2 == 0) {
            even.push_back(x);
        }
        else {
            odd.push_back(x);
        }
    }

    if (odd.size() % 2 == 1) {
        int from_odd = 0;
        int take = odd[0];
        for (int i = 0; i < odd.size(); i++) take = min(take, odd[i]);
        while (take % 2 == 1) {
            take = make(take);
            from_odd++;
        }

        int from_even = 1e8;
        for (auto n: even) {
            int cnt = 0;
            while (n % 2 == 0) {
                n = make(n);
                cnt++;
            }
            from_even = min(from_even, cnt);
        }

        cout << min(from_even, from_odd) << "\n";
    }
    else {
        cout << 0 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    int k;
    cin >> k;

    while (k--) {
        solve();
    }

    return 0;
}