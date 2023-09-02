#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
  
typedef long long ll;

ll n, k;
bool check(vector<ll> &a, ll mid) {
    ll cnt = 0;
    int i = 0;
    while (i < n) {
        cnt++;
        ll cur_max = 0;
        int j = i;
        while (j < n) {
            cur_max = max(cur_max, a[j]);
            if ((j - i + 1) * cur_max <= mid) {
                j++;
            }
            else {
                break;
            }
        }
        i = j;
    }
    return cnt <= k;
}

void solve() {
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    ll l = *max_element(all(a));
    ll r = 1e18;
    int res = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(a, mid)) {
            res = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << res << "\n";
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