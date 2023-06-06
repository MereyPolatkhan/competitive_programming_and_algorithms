#include <bits/stdc++.h>



using namespace std;

typedef long long ll;


void solve() { 
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    bool flag = false;
    for (int i = 1; i <= n - 1; i++) {
        if (a[i] < a[i + 1]) continue;
        else flag = true;
    }

    if (n % 2 == 0 || flag) {
        cout << "YES\n";
    }  
    else {
        cout << "NO\n";
    }
}



int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }


    return 0;
}