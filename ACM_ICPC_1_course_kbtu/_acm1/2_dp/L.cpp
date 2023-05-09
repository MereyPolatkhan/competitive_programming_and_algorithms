#include <bits/stdc++.h>


using namespace std;

#define N 100000

vector<int> dp(N, 1e9);

int sum(int n){ 
    int mn = 1e9;

    for (int i = 1; i <= n / 2; i++) {
        mn = min(mn, dp[i] + dp[n - i]);
    }
    // cout << "sum : " << mn << "\n";
    return mn;
}

int mult(int n) {
    int mn = 1e9;

    for (int i = 1; i <= sqrt(n); i++){ 
        if (n % i == 0)
            mn = min(mn, dp[i] + dp[n / i]);
    }

    // cout << "mult : " << mn << "\n";


    return mn;
}

int main() {
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;


    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    for (int i = 5; i <= n; i++) {
        dp[i] = min(sum(i), mult(i));
    }
    

    for (int i = 1; i <= n; i++) {
        cout << i << " :: " << dp[i] << "\n";
    }


    // cout << dp[n];

    return 0;
}