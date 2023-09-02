#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < (k - 3); i++) cout << 1 << " ";
    n = n - (k - 3);

    if (n % 2 == 1) {
        cout << n / 2 << " " << n / 2 << " " << 1 << "\n";
        return;
    }
    n /= 2;

    if (n % 2 == 1) {
        cout << n - 1 << " " << n - 1 << " " << 2 << "\n";
    }
    else {
        cout << n << " " << n / 2 << " " << n / 2 << "\n";
    }

}

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

