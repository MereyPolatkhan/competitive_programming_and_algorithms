#include <bits/stdc++.h>

using namespace std;




void solve(){
    int n;
    cin >> n;
    int a[n];
    int minn = a[0];
    int maxx = a[0];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        minn = min(minn, a[i]);
        maxx = max(maxx, a[i]);
    }

    int detect = 1e8;
    
    for (int i = 1; i < n; i++) {
        if (a[i - 1] < a[i]) {
            detect = 1;
        }
        else if (a[i - 1] > a[i]) {
            detect = -1;
        }

        if (detect != 1e8) {
            if (detect == 1 && a[i - 1] > a[i]) {
                if (abs(a[i-1] - a[i]) > 1 && a[0] == a[i] && abs(a[i-1] - a[i]) % 2 == 0) {
                    cout << abs(a[i-1] - a[i]) /2 +  a[i] << "\n";
                }
                else {
                    cout << -1 <<"\n";
                    return;
                }
            }
            else if (detect == -1 && a[i - 1] < a[i]) {
                if (abs(a[i-1] - a[i]) > 1 && a[0] == a[i] && abs(a[i-1] - a[i]) % 2 == 0) {
                    cout << abs(a[i-1] - a[i]) /2 +  a[i] << "\n";
                }
                else {
                    cout << -1 <<"\n";
                    return;
                }
            }
        }
    }
    if (detect == 1e8) {
        cout << 1 << "\n";
    }
    else {
        cout << -1 << "\n";
    }

}



int main() {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}