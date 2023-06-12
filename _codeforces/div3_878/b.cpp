#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;
typedef pair<int, int> pii;

ll power(ll x, ll y)
{
    ll temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else {
        if (y > 0)
            return x * temp * temp;
        else
            return (temp * temp) / x;
    }
}

void solve() {

    ll n, k;
    cin >> n >> k;

    // cout << "log2(n)= " << log2(n) << "   res= ";
    if (log2(n) >= (double)k) {
        // cout << "  if: ";
        cout << power(2, k) << "\n";
    }
    else {
        // cout << "  else: ";
        cout << n + 1 << "\n";
    }

    // double l = min(log2(n), k - 1);
    // if (floor(l) == ceil(l)) {
    //     cout << pow(2, l + 1) << "\n";
    // }
    // else {
    //     cout << pow(2, l) + 1 << "\n";
    // }

}

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
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
