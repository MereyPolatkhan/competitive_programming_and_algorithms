#include <bits/stdc++.h>

using namespace std;

vector<int> dp(100000, 0);
vector<int> a(100000, 0);

int main() {
    int s, n;
    cin >> s >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dp[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        int w = a[i];
        for (int j = s; j >= w; j--) {
            if (dp[j - w] == 1) {
                dp[j] = 1;
            }
        }
    }

    int res = 0;
    for (int j = s; j >= 0; j--) {
        if (dp[j] == 1) {
            res = j;
            break;
        }
    }
    cout << res;
    return 0;   
}