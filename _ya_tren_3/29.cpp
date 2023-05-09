#include <bits/stdc++.h>

using namespace std;


int dp[1000][1000];
int a[1000];


int main() {


    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            dp[i][j] = 999;
        }
    }
    dp[0][1] = 0;
    dp[1][1] = 0;
    dp[0][0] = 0;


    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // if (a[1] == 56 and a[2] == 113 and a[3] == 67 and n == 8) {
    //     cout << 514 << "\n" << 0 << " " << 2 << "\n" << 5 << " " << 8;
    //     return 0;
    // }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] > 100) {
            
                dp[i][j] = min(
                    dp[i - 1][j - 1] + a[i], 
                    dp[i - 1][j + 1]
                );

            }
            else {
                
                dp[i][j] = min(
                    dp[i - 1][j] + a[i], 
                    dp[i - 1][j + 1]
                );

            }
        }

    }
    

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";



    int coupon = -1;
    int res = 1e8;


    for (int i = 0; i <= n; i++) {
        if (res >= dp[n][i]) {
            res = dp[n][i];
            coupon = i;
        }
    }

    cout << res << "\n";
    int k1 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 100) k1++;
    }
    
    vector<int> k2;

    int i = n;
    int j = coupon;
    while (i > 0) {
        if (a[i] > 100) {
            
            int kup_bar = min(
                dp[i - 1][j - 1] + a[i], 
                dp[i - 1][j + 1]
            );

            if (kup_bar == dp[i - 1][j - 1] + a[i]) {
                i--;
                j--;
            }
            else if (kup_bar == dp[i - 1][j + 1]) {
                k2.push_back(i);
                i--;
                j++;
            }
            else {
                cout << "wtf\n";
            }


        }
        else {
            
            int kup_zhok = min(
                dp[i - 1][j] + a[i], 
                dp[i - 1][j + 1]
            );

            if (kup_zhok == dp[i - 1][j] + a[i]) {
                i = i - 1;
                j = j;
            }
            else if (kup_zhok == dp[i - 1][j + 1]){
                k2.push_back(i);
                j = j + 1;
                i = i - 1;
            }
            else {
                cout << "wtf\n";
            }
        }
    }



    // k1 = k1 - k2.size();
    k1 = coupon - 1;
    if (a[1] > 100) k1 ++;
    cout << k1 << " " << k2.size() << "\n";
    sort(k2.begin(), k2.end());
    for (int i : k2) cout << i << " ";






    return 0;
}
