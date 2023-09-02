#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;


int n;

void solve() {
    cin >> n;

    vector<int> a(n);
    
    ll sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 3 != 0) {
        cout << 0 << "\n";
        return;
    }

    int cnt = 0;

    ll temp = 0;
    for (int i = 0; i < n; i++) {
        temp += a[i];
        if (temp == sum / 3) {}
    }


}



int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

