#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;




void solve() {
    ll d, n;
    cin >> d >> n;

    ll x = 0;   
    if (n % 4 == 1) {
        n *= -1;
    }
    else if (n % 4 == 2) {
        n = 1;
    }
    else if (n % 4 == 3) {
        n++;
    }
    else {
        n = 0;
    }
    // cout << "d : " << d << " n: " << n << "  res: ";
    if (d % 2 == 0) {
        
        cout << d + n << "\n";
    }
    else {
        cout << d - n << "\n";
    }
}

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

/*  things to check:
    1) long long    
    2) array sizes
    3) corner cases (n = 1, n = 0, etc.)
    4) clear
*/
