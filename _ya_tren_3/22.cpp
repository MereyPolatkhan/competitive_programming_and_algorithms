#include <bits/stdc++.h>


using namespace std;

int dp[10000];


int main() {    
 
    int n, k;
    cin >> n >> k;

    dp[1] = 1;
    dp[2] = 1;


    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 1) {
                dp[i] += dp[i - j];
            }
            else {
                break;
            }
        }
    }

    cout << dp[n];


    return 0;
}