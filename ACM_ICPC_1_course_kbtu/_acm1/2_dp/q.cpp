#include <bits/stdc++.h>


using namespace std;



void binary(int n, vector<int> & dp) {
    int l = 0;
    int r = dp.size() - 1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (n <= dp[mid]) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    dp[l] = n;
}

void solve(int n) {
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (a.size() == 0 || a.back() < x) {
            a.push_back(x);
        }
        else {
            binary(x, a);
        }
    }

    cout << a.size() << "\n";
}

int main() {    
    
    int n;
    while (cin >> n) {
        solve(n);
    }



    return 0;
}