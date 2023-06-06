#include <bits/stdc++.h>



using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int stop = -1;

    for (int i = 1; i <= n; i++) {
        if (a[i] % k != 0) {
            stop = i;
            break;
        }
    }

    

}


int main() {
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }




    return 0;
}