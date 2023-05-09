#include <bits/stdc++.h>


using namespace std;

int n;
vector<int> dp;

void linear(int n) {
    for (int i = 0; i < dp.size(); i++) {
        if (n <= dp[i]) {
            dp[i] = n;
            break;
        }
    }
}

void binary(int n) {
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

int main() {    
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int n: a) {
        if (dp.size() == 0 || dp.back() < n) {
            dp.push_back(n);
        }
        else {
            // linear(n);
            binary(n);
        }
        
    }

    // for (int i: dp) cout << i << " ";
    cout << dp.size();




    return 0;
}